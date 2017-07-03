#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
typedef long long ll;
int N,l[100000],r[100000];

int main() {
    cin>>N;
    rep(i,N)cin>>l[i]>>r[i];
    map<ll,int> L,R;
    ll dl=l[0],dr=l[0],ret=0; 
    L[0]=1, R[0]=1;
    rep1(i,N){
        dl -= r[i]-l[i];
        dr += r[i-1]-l[i-1];
        ll lmax; { auto it=L.rbegin(); lmax=dl+it->first; }
        ll rmin; { auto it=R.begin();  rmin=dr+it->first; }
        if(l[i]<lmax) {
            ret += lmax-l[i];
            L[l[i]-dl] += 2;
            auto it=L.rbegin();
            if(--it->second==0) L.erase(it);
            R[lmax-dr]++;
        } else if(l[i]>rmin) {
            ret += l[i]-rmin;
            R[l[i]-dr] += 2;
            auto it=R.begin(); rmin=dr+it->first;
            --it->second; if(it->second==0) R.erase(it);
            L[rmin-dl]++;
        } else {
            L[l[i]-dl]++;
            R[l[i]-dr]++;
        }
    }
    cout<<ret<<endl;
    return 0;
}
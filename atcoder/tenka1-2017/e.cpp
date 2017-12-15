#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<double> a(N),b(N),c(N);
    rep(i,N){
        a[i]=b[i]=c[i]=i;
        // cin>>a[i]>>b[i]>>c[i];
    }
    int M = N*(N-1)/2;
    vector<double> xs,ys;

    rep(i,N)rep(j,i){
        xs.push_back((b[j]*c[i]-b[i]*c[j])/(b[j]*a[i]-b[i]*a[j]));
        ys.push_back((a[j]*c[i]-a[i]*c[j])/(a[j]*b[i]-a[i]*b[j]));
    }

    return 0;
}

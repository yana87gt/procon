#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> s(n);
    rep(i,n) cin>>s[i];
    if(*min_element(all(s)) == 0){
        cout<<n<<endl;
        return 0;
    }
    ll seq = 1;
    int res = 0;
    int l = 0;
    rep(r,n){
        seq *= s[r];
        while(l<=r && seq>k){
            seq /= s[l];
            l++;
        }
        res = max(res, r-l+1);
    }
    cout<<res<<endl;
    return 0;
}

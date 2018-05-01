#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

void solve(){
    int S;
    cin>>S;
    vector<int> d(S),a(S),b(S),m(S),n(S);
    rep(i,S) {
        cin>>d[i]>>a[i]>>b[i];
        m[i] = d[i] + a[i];
        n[i] = d[i] - b[i];
    }

    // rep()

}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

ll solve(){
    int R,C;
    ll B;
    cin>>R>>B>>C;
    vector<ll> m(C),s(C),p(C);
    rep(i,C){
        cin>>m[i]>>s[i]>>p[i];
    }


}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ", _+1);
        cout<<solve()<<endl;
    }
    return 0;
}

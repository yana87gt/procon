#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

#define updmin(x,v) (x = min(x,v))

int main(void){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    int water_sum = accumulate(all(a), 0);
    vector<int> bs = b;
    sort(all(bs),greater<int>());
    int cap_sum = 0;
    int B = 0;
    rep(i,n){
        cap_sum += bs[i];
        if(cap_sum >= water_sum){
            B = i+1;
            break;
        }
    }
    cap_sum = accumulate(all(b), 0);

    vector<vector<int>> cur(n+2, vector<int>(cap_sum*2+3));
    cur[0][cap_sum] = 0;
    rep(i,n){
        vector<vector<int>> nxt(n+2, vector<int>(cap_sum*2+3, INF));
        rep(j,B+1){
            for(int k = -cap_sum; k <= +cap_sum; k++){
                updmin(nxt[j+1][k-(b[i]-a[i])+cap_sum], cur[j][k+cap_sum]);
                updmin(nxt[j][k+a[i]+cap_sum], cur[j][k+cap_sum]+a[i]);
            }
        }
        cur = nxt;
    }

    int res = INF;
    for(int k = -cap_sum; k <= 0; k++){
        updmin(res,cur[B][k+cap_sum]);
    }
    cout<<B<<" "<<res<<endl;

    return 0;
}

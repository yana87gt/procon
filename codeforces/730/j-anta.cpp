#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 1e9
#define updmin(x,v) (x = min(x,v))

int needBottle(int W, vector<int> b){
    sort(all(b),greater<int>());
    int cnt = 0;
    for(int x : b){
        cnt++;
        W -= x;
        if(W<=0) break;
    }
    return cnt;
}

using P = pair<int,int>;

int main(void){
    int N;
    cin>>N;
    vector<int> a(N),b(N);
    rep(i,N) cin>>a[i];
    rep(i,N) cin>>b[i];
    int W = accumulate(all(a),0);
    vector<P> cur(W+1, {INF,INF});
    cur[0] = {0,0};
    rep(i,N){
        vector<int> nxt(W+1, INF);
        rep(j,W+1)if(cur[j] < P(INF,INF)){
            updmin(nxt[j], P(nxt[j].first, cur[j]+a[i]));
            updmin(nxt[min(W,j+b[i])], P(nxt[min(W,j+b[i])].first+1, cur[j]+B));
        }
        cur = move(nxt);
    }
    cout<<needBottle(W,b)<<" "<<cur[W].second<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

using P = pair<ll,ll>;
#define v first
#define w second

// v高い順（vが同じならw軽い方優先）
bool comp(P a, P b){
    return a.v == b.v ? a.w < b.w : a.v > b.v;
}

int main(void){
    ll N,W;
    cin>>N>>W;
    vector<P> a(N);
    rep(i,N){
        ll v,w;
        cin>>v>>w;
        a[i] = {v,w};
    }
    vector<P> dp = {{0,0}};

    rep(i,N){
        vector<P> tmp;
        for(P s : dp){
            tmp.push_back(s);
            tmp.push_back({s.v + a[i].v, s.w + a[i].w});
        }

        sort(all(tmp),comp);
        dp.clear();
        ll w_border = W+1;
        for(P s : tmp){
            if( w_border > s.w){
                w_border = s.w;
                dp.push_back(s);
            }
        }
    }
    cout<<dp[0].v<<endl;
    return 0;
}

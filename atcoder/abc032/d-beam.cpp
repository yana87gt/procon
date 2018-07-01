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
    sort(all(a),comp);
    ll sum = 0;
    vector<ll> rem(N);
    for(int i = N-1; i>=0; i--){
        rem[i] = sum;
        sum += a[i].v;
    }
    vector<P> dp = {{0,0}};

    ll max_state = 0;
    rep(i,N){
        vector<P> tmp;
        for(auto& s : dp){
            tmp.push_back(s);
            if(s.w + a[i].w <= W){
                tmp.push_back({s.v + a[i].v, s.w + a[i].w});
            }
        }

        sort(all(tmp),comp);
        dp.clear();
        ll w_border = W+1;
        ll max_v = tmp[0].v;
        for(auto& s : tmp){
            if( w_border > s.w && max_v <= s.v+rem[i]){
                w_border = s.w;
                dp.push_back(s);
            }
        }
        cout<<dp.size()<<endl;
        max_state = max(max_state,(ll)dp.size());
        // assert((ll)dp.size() <= N*N*2);
    }
    cout<<max_state<<endl;
    cout<<dp[0].v<<endl;
    return 0;
}

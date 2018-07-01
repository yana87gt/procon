#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

using P = pair<double,double>;
#define v first
#define w second

// v/w 高い順
bool comp1(P a, P b){
    return a.v*b.w > b.v*a.w;
}

// v高い順（vが同じならw軽い方優先）
bool comp2(P a, P b){
    return a.v == b.v ? a.w < b.w : a.v > b.v;
}

int main(void){
    int N,W;
    cin>>N>>W;
    vector<P> a(N);
    rep(i,N){
        double v,w;
        cin>>v>>w;
        a[i] = {v,w};
    }
    sort(all(a),comp1);
    vector<P> dp = {{0,0}};

    rep(i,N){
        vector<P> tmp;
        for(auto& s : dp){
            tmp.emplace_back(s);
            if (s.w + a[i].w <= W) {
                tmp.emplace_back(s.v + a[i].v, s.w + a[i].w);
            }
        }

        sort(all(tmp),comp2);
        dp.clear();
        double w_border = W+1;
        for(auto& s : tmp){
            if( w_border > s.w){
                w_border = s.w;
                dp.push_back(s);
            }
        }
        // if((int)dp.size() > N) dp.resize(N);
        assert((int)dp.size() <= N*N);
    }
    // cout<<dp[0].v<<endl;
    printf("%.10f\n", dp[0].v);
    return 0;
}

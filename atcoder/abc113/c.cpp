#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n, m;
    cin>>n>>m;
    vector<int> p(m),y(m),x(m);
    map<int,vector<pair<int,int>>> vp;
    rep(i,m){
        cin>>p[i]>>y[i];
        vp[p[i]].push_back({y[i],i});
    }
    for(auto &itr : vp){
        auto &vec = itr.second;
        sort(all(vec));
        rep(i,vec.size()){
            x[vec[i].second] = i+1;
        }
    }
    rep(i,m){
        printf("%06d%06d\n", p[i], x[i]);
    }
    return 0;
}

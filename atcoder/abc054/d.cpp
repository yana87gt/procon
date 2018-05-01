#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

typedef pair<pair<int,int>,int> P;

int main(void){
    int n,ma,mb;
    cin>>n>>ma>>mb;
    vector<P> v(n);
    rep(i,n){
        int a,b,c;
        cin>>a>>b>>c;
        v[i] = {{a,b},c};
    }

    map<pair<int,int>,int> cost;
    cost[{0,0}] = 0;
    rep(i,n){
        for(auto itr = cost.rbegin(); itr!=cost.rend(); ++itr){
            int a = v[i].first.first + itr->first.first;
            int b = v[i].first.second + itr->first.second;
            int c = v[i].second + itr->second;
            if(cost.count({a,b})){
                cost[{a,b}] = min(cost[{a,b}], c);
            }else{
                cost[{a,b}] = c;
            }
        }
    }

    int mn = INF;
    cost.erase(cost.begin());
    for(auto itr : cost){
        if(itr.first.first * mb == itr.first.second * ma){
            mn = min(mn, itr.second);
        }
    }
    cout<<((mn==INF) ? -1 : mn)<<endl;
    return 0;
}

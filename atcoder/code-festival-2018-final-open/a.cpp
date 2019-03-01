#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)

using Cost = ll;
struct Edge{
    Cost cost;
    int to;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};


int main(void){
    int n, m;
    cin>>n>>m;
    vector<vector<Edge>> g(n);
    ll res = 0;
    rep(i,m){
        int a,b,l;
        cin>>a>>b>>l;
        a--,b--;
        g[a].push_back({l,b});
        g[b].push_back({l,a});
    }
    rep(i,n){
        map<int,ll> costs;
        for (Edge e : g[i]){
            costs[e.cost] ++;
        }
        for(auto itr : costs){
            int a = itr.first;
            if (a < 2540/2){
                res += costs[a]*costs[2540-a];
            }
            if (a == 2540/2){
                res += costs[a]*(costs[a]-1)/2;
            }
        }
    }
    cout << res << endl;

    return 0;
}

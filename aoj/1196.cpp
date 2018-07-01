#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()

using P = pair<int,int>;
using Edge = P; // <dist,to>
#define cost first
#define to second
vector<vector<Edge>> g;

// <dist,id>
P farthest(int from, int v, int cost){
    P far = {cost,v};
    for(Edge e : g[v]){
        if(e.to == from) continue;
        if((int)g[e.to].size() == 1) continue;
        P res = farthest(v, e.to, cost+e.cost);
        far = max(far,res);
    }
    return far;
}

int main(void){
    int n;
    while(cin>>n,n){
        vector<int> p(n+1),d(n+1);
        g = vector<vector<Edge>>(n+1);
        for(int i=2;i<=n;i++) cin>>p[i];
        for(int i=2;i<=n;i++) cin>>d[i];
        for(int i=2;i<=n;i++){
            g[i].push_back({d[i],p[i]});
            g[p[i]].push_back({d[i],i});
        }
        int all_size = accumulate(all(d),0);
        int one_way = farthest(-1,farthest(-1,1,0).second,0).first;
        int leaf_cost = 0;
        rep1(i,n){
            if((int)g[i].size() == 1){
                leaf_cost += g[i][0].first;
            }
        }
        if(n<=3){
            cout<<all_size<<endl;
        }else{
            cout<<all_size*3 - one_way - leaf_cost*2<<endl;
        }
    }

    return 0;
}

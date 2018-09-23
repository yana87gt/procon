#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define bit(k) (1<<(k))
#define INF 1e9

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}

struct Edge{
    double cost;
    int to,used;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

int main(void){
    int n,m,p,a,b;
    while(cin>>n>>m>>p>>a>>b, m){
        a--,b--;
        int t[8];
        vector<vector<Edge>> g(m);
        rep(i,n) cin>>t[i];
        rep(i,p){
            int x,y;
            double z;
            cin>>x>>y>>z;
            x--,y--;
            g[x].push_back({z,y,0});
            g[y].push_back({z,x,0});
        }
        double dp[30][1<<8];
        Fill(dp, INF);
        priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
        qu.push({dp[a][0] = 0, a,0});
        while(qu.size()){
            Edge cur = qu.top(); qu.pop();
            int v = cur.to;
            int used = cur.used;
            if(dp[v][used] < cur.cost) continue;
            for(Edge e : g[v]){
                rep(k,n){
                    if(used & bit(k)) continue;
                    if( dp[e.to][used|bit(k)] > cur.cost + e.cost/t[k]){
                        dp[e.to][used|bit(k)] = cur.cost + e.cost/t[k];
                        qu.push({dp[e.to][used|bit(k)], e.to, used|bit(k)});
                    }
                }
            }
        }
        double res = INF;
        rep(mask,1<<n){
            res = min(res, dp[b][mask]);
        }
        if(res == INF){
            cout<<"Impossible"<<endl;
        }else{
            printf("%.3f\n",res);
        }
    }
    return 0;
}

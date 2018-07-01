#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define vec2(Y,X,T,N,I) vector<vector<T>> N(Y,vector<T>(X,I))
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
int main(void){
    int N,M,C,S,G;
    while(cin>>N>>M>>C>>S>>G, N|M){
        vec2(N,N,int,d,INF);
        vec2(N,N,int,c,INF);
        rep(i,M){
            int x,y,d_,c_;
            cin>>x>>y>>d_>>c_;
            x--,y--;
            d[x][y] = d[y][x] = d_;
            c[x][y] = c[y][x] = c_;
        }
        vector<int> p(C);
        vector<vector<int>> q(C),r(C);
        rep(i,C) cin>>p[i];
        rep(i,C){
            q[i].resize(p[i]-1);
            rep(j,p[i]-1){
                cin>>q[j];
            }
            r[i].resize(p[i]);
            rep(j,p[i]){
                cin>>r[j];
            }
        }
        
    }
    return 0;
}

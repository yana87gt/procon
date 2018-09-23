#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const int INF = 1e9;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}

using Cost = int;
struct Edge{
    Cost cost;
    int y,x,foot;
    bool operator>(const Edge &right)const{
        return cost > right.cost;
    }
};

int X,Y;
char s[60][30];
Cost dp[60][30][2];

int main(void){
    while(cin>>X>>Y, X|Y){
        Fill(dp, (Cost)INF);
        vector<int> T,S;
        rep(y,Y)rep(x,X){
            cin>>s[y][x];
            if(s[y][x] == 'T'){
                T.push_back(x);
                s[y][x] = '0';
            }
            if(s[y][x] == 'S') {
                S.push_back(x);
                s[y][x] = '0';
            }
        }
        priority_queue<Edge,vector<Edge>,greater<Edge>> qu;
        for(int x : S)rep(foot,2){
            dp[Y-1][x][foot] = 0;
            qu.push({0,Y-1,x,foot});
        }

        while(qu.size()){
            Edge cur = qu.top(); qu.pop();
            int y = cur.y;
            int x = cur.x;
            int foot = cur.foot;
            if(dp[y][x][foot] < cur.cost) continue;
            for(int dx=-3; dx<=3; dx++){
                if(foot==0 && dx<=0) continue;
                if(foot==1 && dx>=0) continue;
                for(int dy=-2; dy<=2; dy++){
                    if(abs(dx)+abs(dy)>3) continue;
                    int ny = y + dy;
                    int nx = x + dx;
                    if(ny<0 || nx<0 || ny>=Y || nx>=X) continue;
                    if(s[ny][nx] == 'X') continue;
                    int c = s[y][x]-'0';
                    if( dp[ny][nx][!foot] > cur.cost + c){
                        dp[ny][nx][!foot] = cur.cost + c;
                        qu.push({dp[ny][nx][!foot], ny,nx,!foot});
                    }
                }
            }
        }

        int res = INF;        
        for(int x : T)rep(foot,2){
            res = min(res,dp[0][x][foot]);
        }
        cout<<(res == INF ? -1 : res)<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
    int R,C,sy,sx,gy,gx;
    cin>>R>>C>>sy>>sx>>gy>>gx;
    bool visited[R+1][C+1]={};
    char c;
    rep1(y,R)rep1(x,C){
        cin>>c;
        visited[y][x] = (c=='#');
    }

    visited[sy][sx] = true;
    queue < pair<int,int> > Q;
    Q.push({sy,sx});
    int dist[R+1][C+1]={};
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};
    while(!Q.empty()){
        int y=Q.front().first;
        int x=Q.front().second;
        Q.pop();
        rep(i,4){
            int nexty = y+dy[i];
            int nextx = x+dx[i];
            if(visited[nexty][nextx])continue;
            visited[nexty][nextx] = true;
            dist[nexty][nextx] = dist[y][x]+1;
            Q.push({nexty,nextx});
        }
    }
    cout<<dist[gy][gx]<<endl;

    return 0;
}

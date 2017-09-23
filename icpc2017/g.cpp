#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int N,M;
int dx[4] = {0,-1,0,+1};
int dy[4] = {+1,0,-1,0};

#define front c[y+dy[dir]][x+dx[dir]]
#define right c[y+dy[(dir+1)%4]][x+dx[(dir+1)%4]]
#define left c[y+dy[(dir+3)%4]][x+dx[(dir+3)%4]]

vector<string> c;

bool dfs(int y,int x,int dir){
    if(c[y][x] == '#')return false;
    if(y==1 || x==1)return true;
    c[y][x] = '*';
    if(right == '.'){        
        dir = (dir+1)%4;
    }
    else if(front != '.'){
        if(left != '.')return false;
        else dir = (dir+3)%4;
    }
    y += dy[dir];
    x += dx[dir];
    return ();
}

int main(void){
    while(cin>>N>>M, N|M){
        c = vector<string>(N+2);
        c[0] = c[N+1] = string(M+2,'#');
        rep(y,N) {
            cin>>c[y+1];
            c[y+1] = "#"+c[y+1]+"#";
        }
        if(solve(2,1,0) && c[N][1]=='*' && c[N][M]=='*' && c[1][M]=='*'){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

        rep(i,N+2)cout<<c[i]<<endl;
    }
    return 0;
}

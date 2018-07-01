#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int Y,X;
bool dfs(vector<string> &s, int y,int x){
    if(x<0 || x>=X || y<0 || y>=Y) return false;
    if(s[y][x] == '1' || s[y][x] == '2') return false;
    if(y == Y-1) return true;
    s[y][x] = '2';
    rep(i,4){
        if(dfs(s,y+dy[i],x+dx[i])){
            return true;
        }
    }
    return false;
}

int main(void){
    while(cin>>Y>>X){
        vector<string> s(Y);
        rep(y,Y){
            cin>>s[y];
        }
        bool ok = false;
        rep(x,X){
            if(dfs(s,0,x)){
                ok = true;
            }
        }
        cout<<((ok) ? "YES" : "NO")<<endl;
    }
    return 0;
}

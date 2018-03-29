#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int y,int x,bool on,vector<string> &c){
    if(c[y][x] == '*') return 0;
    int res = (on ? 1 :0);
    c[y][x] = '*';
    rep(i,4){
        res += dfs(y+dy[i],x+dx[i],!on,c);
    }
    return res;
}

void visit(int y,int x,vector<string> &c){
    if(c[y][x] == '*') return;
    c[y][x] = '*';
    rep(i,4){
        visit(y+dy[i],x+dx[i],c);
    }
}

int main(void){
    int Y,X;
    cin>>Y>>X;
    vector<string> c(Y+2);
    c[0] = c[Y+1] = string(X+2,'*');
    rep(i,Y) {
        string s;
        cin>>s;
        c[i+1] = "*" + s + "*";
    }
    Y+=2; X+=2;
    int res = 0;
    rep(y,Y)rep(x,X){
        if(c[y][x]=='.'){
            vector<string> c1=c,c2=c;
            res += max(dfs(y,x,true,c1),dfs(y,x,false,c2));
            visit(y,x,c);
        }
    }
    cout<<res<<endl;
    return 0;
}

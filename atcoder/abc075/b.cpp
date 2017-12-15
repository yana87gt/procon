#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int H,W;
    cin>>H>>W;
    vector<string> s(H);
    rep(y,H)cin>>s[y];

    rep(y,H)rep(x,W){
        if(s[y][x] != '.')continue;
        int cnt = 0;
        for(int dy:{-1,0,+1}){
            for(int dx:{-1,0,+1}){
                if(y+dy==-1 || y+dy==H || x+dx==-1 || x+dx==W)continue;
                if(s[y+dy][x+dx]=='#')cnt++;
            }
        }
        s[y][x]='0'+cnt;
    }
    rep(y,H){
        cout<<s[y]<<endl;
    }
    return 0;
}

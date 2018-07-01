#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int Y,X;
    cin>>Y>>X;
    vector<string> s(Y+2);
    s[0] = s[Y+1] = string(X+2,'.');
    rep(y,Y){
        cin>>s[y+1];
        s[y+1] = "#"+s[y+1]+"#";
    }
    rep1(y,Y)rep1(x,X){
        if(s[y][x] == '.')continue;
        int dy[] = {1,-1,0,0};
        int dx[] = {0,0,1,-1};
        bool ng = true;
        rep(i,4){
            if(s[y+dy[i]][x+dx[i]] == '#'){
                ng = false;
            }
        }
        if(ng){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}

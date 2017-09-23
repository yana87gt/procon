#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define y first
#define x second

int main(void){
    int N;
    cin>>N;
    vector<string> s(N);
    rep(i,N)cin>>s[i];

    bool yes = false;
    int x1=N,y1=N,x2=-1,y2=-1;
    rep(y,N)rep(x,N)if(s[y][x]=='4'){
        x1=min(x1,x);
        y1=min(y1,y);
        x2=max(x2,x);
        y2=max(y2,y);
        yes = true;
    }

    rep(y,N)rep(x,N){
        if(x>=x1-1 && x<=x2+1 && y>=y1-1 && y<=y2+1){
            if(x>=x1 && x<=x2 && y>=y1 && y<=y2){
                yes &= s[y][x]=='4';
            }else if((x==x1-1 || x==x2+1)&&(y==y1-1 || y==y2+1)){
                yes &= s[y][x]=='1';
            }else{
                yes &= s[y][x]=='2';
            }
        }else{
            yes &= s[y][x]=='0';
        }
    }
    cout<<(yes ? "Yes" : "No")<<endl;
    return 0;
}

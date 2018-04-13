#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool s[70][4];

void move(int &pos, int goal){
    while(pos < goal){
        bool ok = true;
        for(int y : {1,2,3}){
            if(!s[pos-1][y]) ok = false;
        }
        if(ok) pos++;
        else break;
    }
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int A;
        rep(y,4)rep(x,70) s[x][y]=false;
        cin>>A;
        int x,y,pos=2;
        int goal = (A<=9) ? 2 : int(ceil(A/3.0))-1;
        while(true){
            cout<<pos<<" "<<2<<endl<<flush;
            cin>>x>>y;
            s[x][y] = true;
            if(x==0 && y==0)break;
            move(pos, goal);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    char c;
    int x=0,y=0,q=0,T,M;

    while(1){
        c = getchar();
        if(c=='\n')break;
        else if(c=='L')x--;
        else if(c=='R')x++;
        else if(c=='U')y++;
        else if(c=='D')y--;
        else if(c=='?')q++;
    }
    M = (int)fabs(x)+fabs(y);
    cin>>T;
    if(T==1)cout<<M+q<<endl;
    else cout<<( M>=q ? M-q : (q-M)%2)<<endl;

    return 0;
}

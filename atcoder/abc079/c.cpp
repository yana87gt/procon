#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int d[4];
    string s;
    cin>>s;
    rep(i,4) d[i] = s[i] - '0';
    char op[2] = {'+','-'};
    int sign[2] = {+1,-1};
    rep(i,2)rep(j,2)rep(k,2){
        if(d[0] + sign[i]*d[1] + sign[j]*d[2] + sign[k]*d[3] == 7) {
            printf("%d%c%d%c%d%c%d=7\n",d[0],op[i],d[1],op[j],d[2],op[k],d[3] );
            return 0;
        }
    }
}

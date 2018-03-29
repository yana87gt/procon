#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)


int main(void){
    int n;
    cin>>n;
    map<int,int> imos;
    rep(i,n){
        int s,e;
        scanf("%d-%d ",&s,&e);
        imos[s-s%5]++;
        e += 4;
        e -= e%5;
        if((e%100)==60) {
            e += 40;
        }
        imos[e]--;
    }
    int l=0;
    rep(i,2401){
        imos[i+1] += imos[i];
        if(!imos[i-1] && imos[i]) l=i;
        if(imos[i-1] && !imos[i]) {
            printf("%04d-%04d\n",l,i);
        }
    }
    return 0;
}

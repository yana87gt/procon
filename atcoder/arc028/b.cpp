#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K,x,valK=0;
    scanf("%d %d",&N,&K);
    int *order = new int[N+1];

    for(int i=1;i<=K;++i){
        scanf("%d",&x);
        order[x] = i;
        if(valK<x)valK = x;
    }

    printf("%d\n",order[valK]);
    for(int i=K+1;i<=N;++i){
        scanf("%d",&x);
        order[x] = i;
        if(valK>x)while(order[--valK]==0);
        printf("%d\n",order[valK]);
    }

    return 0;
}

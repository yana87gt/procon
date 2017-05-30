#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
    int mine;
    int yours;
}WEY;

int comp_boy_yours(const void *a,const void *b){
    WEY boy1 = *(WEY *)a;
    WEY boy2 = *(WEY *)b;
    return boy1.yours-boy2.yours;
}

int comp_girl_mine(const void *a,const void *b){
    WEY girl1 = *(WEY *)a;
    WEY girl2 = *(WEY *)b;
    return girl1.mine-girl2.mine;
}

int main(void){
    int N,M,i,j,cnt1=0,cnt2=0;
    WEY *B,*G;

    cin>>N;
    cin>>M;

    B = (WEY*)malloc(sizeof(WEY)*N);
    G = (WEY*)malloc(sizeof(WEY)*M);

    for(i=0;i<N;i++){
        cin >> B[i].mine;
        cin >> B[i].yours;
    }
    for(j=0;j<M;j++){
        cin >> G[j].mine;
        cin >> G[j].yours;
    }
    qsort(B,N,sizeof(WEY),comp_boy_yours);
    qsort(G,M,sizeof(WEY),comp_girl_mine);

    for(i=0,j=0;i<N&&j<M;j++){
        if(B[i].yours<=G[j].mine){
            cnt1++;
            i++;
        }
    }
    for(i=N-1,j=M-1;i>=0&&j>=0;j--){
        if(B[i].yours<=G[j].mine){
            cnt2++;
            i--;
        }
    }
    cout<<(cnt1>cnt2 ? cnt1 : cnt2)<<endl;

    return 0;
}

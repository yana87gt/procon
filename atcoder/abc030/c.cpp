#include <stdio.h>
#include <stdlib.h>

int count=0,time=0;
int N,M,X,Y,i,j;
bool AtoB(int *a){
    while(i++,a[i]<time&&i<=N);//次の便を待つ
    if(i==N+1)return false;
    time=a[i]+X;
    count++;
    return true;
}

bool BtoA(int *b){
    while(j++,b[j]<time&&j<=M);//次の便を待つ
    if(j==M+1)return false;
    time=b[j]+Y;
    count++;
    return true;
}


int main(void){
    int *a,*b;
    scanf("%d %d %d %d",&N,&M,&X,&Y);
    a = (int*)malloc(sizeof(int)*(N+2));
    b = (int*)malloc(sizeof(int)*(M+2));

    for(i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    for(j=1;j<=M;j++){
        scanf("%d",&b[j]);
    }

    /*A->B*/
    i=0; j=0;
    while(1){
        if(!AtoB(a))break;
        if(!BtoA(b))break;
    }

    printf("%d\n",count/2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(void){
    int *a,*b;
    int N,M,i,j;
    scanf("%d %d",&N,&M);
    if(N<M){
        printf("NO\n");
        return 0;
    }
    a = (int*)malloc(sizeof(int)*(N+2));
    b = (int*)malloc(sizeof(int)*(M+2));
    for(i=1;i<=N;i++) scanf("%d",&a[i]);
    for(j=1;j<=M;j++) scanf("%d",&b[j]);
    sort(a+1,a+N+1);
    sort(b+1,b+M+1);

    for(i=1,j=1;j<=M;i++,j++){
        while(a[i]<b[j]&&i<=N)i++;
        if(i>N){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

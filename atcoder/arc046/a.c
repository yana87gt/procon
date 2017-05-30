#include<stdio.h>

int main(void){
    int N,digit;
    scanf("%d",&N);
    digit=(N-1)/9+1;
    while(digit--)printf("%d",N%9==0 ? 9 : N%9);
    printf("\n");
    return 0;
}

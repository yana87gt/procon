#include <stdio.h>
 
int main(void){
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    double taka=(double)B/A,aoki=(double)D/C;
    if(taka>aoki)printf("TAKAHASHI\n");
    else if(taka<aoki)printf("AOKI\n");
    else printf("DRAW\n");
    return 0;
}

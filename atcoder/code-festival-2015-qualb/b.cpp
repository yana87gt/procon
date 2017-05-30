#include <stdio.h>
using namespace std;

int main(void){
    int i,N,M,score,max=0,m_score,a[100001]={};
    bool eq=false;
    scanf("%d %d",&N,&M);

    for(i=1;i<=N;i++){
        scanf("%d",&score);
        a[score]++;
        if(a[score]==max){
            eq=true;
        }else if(a[score]>max){
            eq=false;
            max=a[m_score=score];
        }
    }

    if(eq==true||N>=max*2)printf("?\n");
    else printf("%d\n",m_score);

    return 0;
}

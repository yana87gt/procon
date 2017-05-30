#include <stdio.h>
int main(void){
    int n,count=0;
    bool nat=true;
    char op;
    while(1){
        scanf("%d%c",&n,&op);
        nat &= (n>0);
        if(op!='*'){
            if(nat)count++;
            nat = true;
        }
        if(op=='\n')break;
    }
    printf("%d\n",count);
    return 0;
}

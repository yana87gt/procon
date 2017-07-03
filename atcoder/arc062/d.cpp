#include <stdio.h>
int main(void){
    char c;
    int p=0;
    while((c=getchar())!='\n'){
        if(c=='g')p++;
        else p--;
    }
    printf("%d\n",p/2);
    return 0;
}

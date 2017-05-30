#include <stdio.h>
#include <string.h>

int main(void){
    char c;
    int biginner=1;

    while(c=getchar(),c!='\n'){
        if(c==' '){
            printf(" ");
        }
        if(c=='L'){
            printf("<");
        }else if(c=='R'){
            printf(">");
        }else if(c=='A'){
            printf("A");
        }
    }
    printf("\n");

    return 0;
}

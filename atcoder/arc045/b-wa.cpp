#include <stdio.h>
#include <string.h>

typedef struct{
    int left;
    int right;
    int sabo;
}Section;

int main(void){
    int N,M,i,j,count=0;
    Section *s;
    int *room,*ans;


    scanf("%d %d",&N,&M);
    s = (Section*)malloc( sizeof(Section)*M);
    room = (int*)malloc( sizeof(int)*N);
    ans = (int*)malloc( sizeof(int)*M);

    for(j=0;j<N;j++){
        room[j]=0;
    }

    for(i=0;i<M;i++){
        ans[i]=0;
        scanf("%d %d",&s[i].left,&s[i].right);
        for(j=s[i].left;j<=s[i].right;j++){
            room[j]++;
        }
    }

    for(i=0;i<M;i++){
        for(j=s[i].left;j<=s[i].right;j++){
            if(room[j]<2){
                break;
            }
        }
        if(j==s[i].right+1){
            s[i].sabo=5;
            count++;
        }
    }
    printf("%d\n",count);
    for(i=0;i<M;i++){
        if(s[i].sabo==5){
            printf("%d\n",i+1);
        }
    }

    return 0;
}

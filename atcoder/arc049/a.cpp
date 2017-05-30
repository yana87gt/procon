#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
    int A,B,C,D,i=-1;
    char s[102]={};

    while(s[i]!='\n'){
        s[++i] = getchar();
    }
    cin>>A>>B>>C>>D;
    for(i=0;;i++){
        if(A==i||B==i||C==i||D==i)cout<<"\"";
        cout<<s[i];
        if(s[i]=='\n')break;
    }

    return 0;
}

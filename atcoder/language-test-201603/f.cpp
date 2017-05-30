#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    char s[102]={},tmp;
    int i=0,N,l,r;
    while(s[i]!='\n')s[++i]=getchar();
    cin>>N;
    while(N--)
    {
        for(cin>>l>>r; l<r; l++,r--)
        {
            tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
        }
    }
    i=0;
    while(s[i]!='\n') cout<<s[++i];
    return 0;
}


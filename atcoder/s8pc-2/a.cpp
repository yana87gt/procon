#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    int cnt=0;
    while(c=getchar(), c!='\n')if((c=='I' && cnt%2==0)||(c=='O' && cnt%2))++cnt;
    if(cnt%2==0 && cnt>0)--cnt;
    cout<<cnt<<endl;
    return 0;
}

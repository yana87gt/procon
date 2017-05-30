#include <bits/stdc++.h>
using namespace std;

int main(void){
    map<char,int> a;
    char c;
    int cnt=0,odd=0;
    while(c=getchar(),c!='\n'){
        cnt++;
        a[c]++;
        if(a[c]&1)odd++;
        else odd--;
    }

    if(odd<=1)cout<<cnt<<endl;
    else cout<<(cnt-odd)/2/odd*2+1<<endl;

    return 0;
}

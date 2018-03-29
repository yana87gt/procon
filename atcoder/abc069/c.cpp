#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    int odd=0,two=0,four=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a&1) odd++;
        else if(a%4==0) four++;
        else two++;
    }
    if(two>0) odd++;
    if(four+1<odd) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}

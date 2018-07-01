#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int a,b;
    cin>>a>>b;
    int res = b;
    rep1(i,a){
        if(i%b==0){
            res = i;
        }
    }
    cout<<res<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int sum = 0;
    rep(i,3){
        int s,e;
        cin>>s>>e;
        sum += s*e/10;
    }
    cout<<sum<<endl;
    return 0;
}

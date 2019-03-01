#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin>>n;
    int cnt = 0;
    rep1(i,100){
        if(i%n==0){
            cnt++;
        }
    }
    cout<<100-cnt<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    int res=100;
    rep(i,n){
        int a,cnt=0;
        cin>>a;
        while(a%2==0){
            a/=2;
            cnt++;
        }
        res=min(cnt,res);
    }
    cout<<res<<endl;
    return 0;
}

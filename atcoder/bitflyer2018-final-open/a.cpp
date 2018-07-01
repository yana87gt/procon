#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    int res = 10;
    rep(i,n){
        int p;
        cin>>p;
        int cnt = 0;
        while(p){
            if(p%10) break;
            p /= 10;
            cnt++;
        }
        res = min(res, cnt);
    }
    cout<<res<<endl;
    return 0;
}

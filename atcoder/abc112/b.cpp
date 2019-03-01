#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 1e9;

int main(void){
    int n, T;
    cin>>n>>T;
    int res = INF;
    rep(i,n){
        int c,t;
        cin>>c>>t;
        if(t<=T){
            res = min(res,c);
        }
    }
    if(res==INF){
        cout<<"TLE"<<endl;
    }else{
        cout<<res<<endl;
    }
    return 0;
}

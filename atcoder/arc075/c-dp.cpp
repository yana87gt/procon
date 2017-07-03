#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,s;
    cin>>N;
    map<int,bool> dp;
    dp[0]=true;
    rep(i,N){
        cin>>s;
        for(auto it=dp.rbegin();it!=dp.rend();++it){
            dp[it->first + s]=true;
        }
    }
    for(auto it=dp.rbegin();it!=dp.rend();++it){
        if(it->first%10){
            cout<<it->first<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}

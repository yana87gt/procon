#include <bits/stdc++.h>
using namespace std;
int main(){    
    int N,W,w,v,res=0;
    map<int,int> dp;
    dp[0]=0;
    cin>>N>>W;
    while(N--){
        cin>>w>>v;
        for(auto it=dp.rbegin();it!=dp.rend();++it){
            int ws=w+it->first,vs=v+it->second;
            if(ws<=W){
                dp[ws]=max(dp[ws],vs);
                res=max(res,dp[ws]);
            }
        }
    }
    cout<<res<<endl;
}

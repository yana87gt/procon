#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k,v,u;
    cin>>k;
    vector<int> dp(k,46);
    dp[1] = 1;
    deque<int> deq = {1};
    while(v = deq.front()){
        deq.pop_front();
        u = (v*10)%k;
        if(dp[u] > dp[v]){
            dp[u] = dp[v];
            deq.push_front(u);
        }
        u = (v+1)%k;
        if(dp[u] > dp[v]+1){
            dp[u] = dp[v]+1;
            deq.push_back(u);
        }
    }
    cout<<dp[v]<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define debug(x) cout<<#x<<": "<<x<<endl

int calc(vector<int>& len){
    int n = len.size();
    int dp[n][2]={};
    dp[0][0] = len[0];

    // i+1の左端を使ってiを操作
    rep1(i,n-1){
        if(len[i] == 1){
            dp[i][0] = dp[i-1][1]+1;
        }else{
            dp[i][0] = max(dp[i-1][0]+len[i]-1,dp[i-1][1]+len[i]);    
        }
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
    }
    return dp[n-1][1];
}

int main(void){
    int N;
    cin>>N;
    string s;
    cin>>s;
    s += "00";
    vector<string> block;
    rep(l,N){
        while(s[l]=='0')l++;
        int r = s.find("00",l);
        if(r == -1) break;
        if(int(s.find("0",l))<r){
            block.push_back(s.substr(l,r-l));
        }
        l = r;
    }

    int sum = 0;
    for(string b : block){
        vector<int> len;
        b += "0";
        rep(l,b.size()){
            int r = b.find("0",l);
            len.push_back(r-l);
            l = r;
        }
        int c1 = calc(len);
        reverse(all(len));
        int c2 = calc(len);
        sum += max(c1,c2);
    }
    cout<<sum<<endl;
    return 0;
}

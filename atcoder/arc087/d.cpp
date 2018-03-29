#include <bits/stdc++.h>
using namespace std;
#define M 20000

int main(void){
    int tx,ty;
    string s;
    cin>>s>>tx>>ty;
    s += "T";
    int init = s.find("T",0);
    tx -= init;
    s = string(s.begin()+init, s.end());
    bitset<M*2> dp[2];
    dp[0][M] = dp[1][M] = 1;
    int cnt = 0, mode = 0;
    for(char c : s){
        if(c=='F') cnt++;
        else{
            dp[mode] = (dp[mode]<<cnt) | (dp[mode]>>cnt);
            cnt = 0;
            mode = !mode;
        }
    }
    cout<<((dp[0][M+tx] && dp[1][M+ty]) ? "Yes" : "No")<<endl;
}

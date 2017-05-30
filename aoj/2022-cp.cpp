#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
 
int N;
vector<string> dp;
 
string merge(string s, string t){
    if(s.find(t) != string::npos)return s;
    for(int i=max(0, (int)(s.size() - t.size())); i<(int)s.size(); ++i){
        if(s.substr(i) == t.substr(0, (int)s.size() - i)){
            return s.substr(0,i) + t;
        }
    }
    return s+t;
}
 
string solve(){
    rep(S, 1<<N){
        if(__builtin_popcount(S) == 1)continue;
        for(int U=S-1&S; U>0; --U&=S){
            dp[S] = min(dp[S], merge(dp[U], dp[S^U]),[](const string &s, const string &t){return s.size() < t.size() || (s.size() == t.size() && s < t);});
        }
    }
    return dp[(1<<N) - 1];
}
 
int main(){
    while(cin >> N, N){
        dp.assign(1<<N, string(100, 'z'));
        rep(i, N)cin >> dp[1<<i];
        cout << solve() << endl;
    }
    return 0;
}
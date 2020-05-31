#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    bool win = true;
    string atc = "atcoder";
    map<char, bool> mp;
    for(char c: atc) mp[c] = true;
    rep(i,n){
        if (s[i] == t[i]) continue;
        if (s[i] == '@' && !mp[t[i]]) {
            win = false;
        }
        if (t[i] == '@' && !mp[s[i]]) {
            win = false;
        }
        if (s[i] != '@' && t[i] != '@') {
            win = false;
        }
    }
    cout << ((win) ? "You can win" : "You will lose") << endl;
    return 0;
}

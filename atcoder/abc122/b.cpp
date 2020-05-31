#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, res = 0;
    map<char,bool> mp;
    mp['A'] = mp['T'] = mp['C'] = mp['G'] = true; 
    rep(i,n){
        if (mp[s[i]]) {
            res = max(res, i-l+1);
        } else l = i+1;
    }
    cout << res << endl;
    return 0;
}

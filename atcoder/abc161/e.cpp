#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int n,k,c;
vector<int> make_dp(string s){
    vector<int> dp(n+2);
    rep1(i,n+1){
        if (s[i] == 'o') {
            if (i-c-1 < 0) dp[i] = 1;
            else dp[i] = dp[i-c-1] + 1;
        } else {
            dp[i] = dp[i-1];
        }
    }
    return dp;
}

int main(void){
    cin >> n >> k >> c;
    string s;
    cin >> s;
    if (n == k) {
        rep1(i,n){
            cout << i << endl;
        }
        return 0;
    }
    s = "x" + s + "x";
    auto stepL = make_dp(s);

    string rs = s;
    reverse(all(rs));
    auto stepR = make_dp(rs);
    reverse(all(stepR));

    set<int> res;
    rep1(i,n) {
        if (s[i] == 'o') {
            res.insert(i);
        }
    }
    if (c == 0) {
        if ((int)res.size() == k) {
            for (int d : res) {
                cout << d << endl;
            }
        }
        return 0;
    }
    rep1(i,n+c+1){
        int l = max(0,i-c-1);
        int r = min(n+1,i);
        if (stepL[l] + stepR[r] >= k) {
            while (res.upper_bound(l) != res.end()) {
                if (*res.upper_bound(l) < r) {
                    res.erase(res.upper_bound(l));
                } else {
                    break;
                }
            }
        }
    }
    for (int d : res) {
        cout << d << endl;
    }
    return 0;
}

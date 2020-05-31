#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> to1, to0;
    to1.push_back(0);
    if (s[0] == '0') to0.push_back(0);
    rep(i,n-1) {
        if (s[i]=='0' && s[i+1]=='1') to1.push_back(i+1);
        if (s[i]=='1' && s[i+1]=='0') to0.push_back(i+1);
    }
    if (s.back() == '0') to1.push_back(n);
    to0.push_back(n);

    int m = to1.size();
    if (m <= k) {
        cout << n << endl;
        return 0;
    }
    int mx = 0;
    rep(i,m-k){
        mx = max(mx, to0[i+k] - to1[i]);
    }
    cout << mx << endl;
    return 0;
}

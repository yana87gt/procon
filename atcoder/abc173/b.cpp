#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void) {
    int n;
    cin >> n;
    map<string, int> cnt;
    rep(i,n){
        string s;
        cin >> s;
        cnt[s]++;
    }
    vector<string> result = {"AC", "WA", "TLE", "RE"};
    for (string r : result) {
        cout << r << " x " << cnt[r] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(v) (v).begin(),(v).end()

string plus_one(string s) {
    int S = s.size();
    if (count(all(s), '9') == S) {
        return "1" + string(S, '0');
    }
    rep(ri,S) {
        int i = S - ri - 1;
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            s[i]++;
            return s;
        }
    }
    assert(false);
}

void solve() {
    int N;
    cin >> N;
    vector<string> x(N);
    rep(i,N){
        cin >> x[i];
    }
    string pre = "0";
    int sum = 0;
    rep(i,N) {
        if (pre.size() < x[i].size()) {
            pre = x[i];
        } else if (pre.size() == x[i].size()) {
            if (pre < x[i]) {
                pre = x[i];
            } else {
                pre = x[i] + "0";
                sum++;
            }
        } else if (pre.size() > x[i].size()) {
            string pre_prefix = pre.substr(0, x[i].size());
            int dig_diff = pre.size() - x[i].size();
            if (pre_prefix < x[i]) {
                pre = x[i] + string(dig_diff, '0');
                sum += dig_diff;
            } else if (pre_prefix > x[i]) {
                pre = x[i] + string(dig_diff + 1, '0');
                sum += dig_diff + 1;
            } else {
                assert(pre_prefix == x[i]);
                string pre_suffix = pre.substr(x[i].size());
                if (count(all(pre_suffix), '9') == dig_diff) {
                    pre = x[i] + string(dig_diff + 1, '0');
                    sum += dig_diff + 1;
                } else {
                    string pre_plus_one = plus_one(pre);
                    sum += pre_plus_one.size() - x[i].size();
                    pre = pre_plus_one;
                }
            }
        } else {
            assert(false);
        }
    }
    cout << sum << endl;
}

int main(void) {
    int T;
    cin >> T;
    rep(testcase, T){
        cout << "Case #" << testcase + 1 << ": ";
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

char get_other(string s){
    return (s == "AB") ? 'C' : ((s == "BC") ? 'A' : 'B');
}

int main(void){
    ll n, a, b, c;
    map<char, ll> m;
    cin >> n >> a >> b >> c;
    m['A'] = a;
    m['B'] = b;
    m['C'] = c;
    vector<string> cmd(n);
    rep(i,n) cin >> cmd[i];
    string res;
    rep(i,n){
        string s = cmd[i];
        cin >> s;
        if (m[s[0]] == 0 && m[s[1]] == 0) {
            cout << "No" << endl;
            return 0;
        }
        if (i < n-1 && m[s[0]] == m[s[1]] && m[get_other(s)] == 0){
            char nxt_other = i == n-1 ? '?' : get_other(cmd[i+1]);
            char down = nxt_other;
            char up = (s[0] == nxt_other) ? s[1] : s[0];
            if (cmd[i] == cmd[i+1]) {
                down = s[0];
                up = s[1];
            }
            res += up;
            m[up]++;
            m[down]--;
        } else if (m[s[0]] < m[s[1]]) {
            res += s[0];
            m[s[0]]++;
            m[s[1]]--;
        } else {
            res += s[1];
            m[s[1]]++;
            m[s[0]]--;
        }
    }
    cout << "Yes" << endl;
    rep(i,n) {
        cout << char(res[i]) << endl;
    }
    return 0;
}

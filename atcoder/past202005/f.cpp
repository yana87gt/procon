#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

char same_char(string s1, string s2){
    set<char> st;
    for (char c : s1) {
        st.insert(c);
    }
    for (char c : s2) {
        if (st.count(c)) {
            return c;
        }
    }
    return '?';
} 

int main(void){
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    string res(n, '?');
    rep(i,(n+1)/2){
        char c = same_char(a[i], a[n-1-i]);
        if (c == '?') {
            cout << -1 << endl;
            return 0;
        }
        res[i] = c;
        res[n-1-i] = c;
    }
    cout << res << endl;
    return 0;
}

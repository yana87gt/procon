#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

set<int> calc(string &a, string &b){
    int A = a.size(), B = b.size();
    set<int> st;
    rep(i,A+1){
        bool ok = true;
        rep(j,B){
            if (i+j >= A) break;
            if (a[i+j] == '?' || b[j] == '?') continue;
            if (a[i+j] != b[j]) ok = false;
        }
        if (ok) st.insert(i);
    }
    return st;
}

int main(void){
    vector<string> vs(3);
    rep(i,3) cin >> vs[i];
    int res = 6000;
    int pos[] = {0,1,2};
    do {
        string &a = vs[pos[0]], &b = vs[pos[1]], &c = vs[pos[2]];
        int A = a.size(), B = b.size(), C = c.size();
        auto fab = calc(a,b), fbc = calc(b,c), fac = calc(a,c);
        for (int x : fab) {
            rep(y, max(B+1, A-x+1)){
                if (y <= B && !fbc.count(y)) continue;
                if (x+y >= A || fac.count(x+y)) {
                    res = min(res, max({A, x+B, x+y+C}));
                }
            }
        }
    } while(next_permutation(pos, pos+3));
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void) {
    int T;
    cin >> T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        int X, Y;
        string s;
        cin >> X >> Y >> s;
        string t;
        rep(i, s.size()) {
            if (s[i] != '?') {
                t.push_back(s[i]);
            }
        }
        int cost = 0;
        rep(i,(int)t.size()-1) {
            string sub = t.substr(i,2);
            if (sub == "CJ") cost += X;
            else if (sub == "JC") cost += Y;
        }
        cout << cost << endl;
    }
    return 0;
}

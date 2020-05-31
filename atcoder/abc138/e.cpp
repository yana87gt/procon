#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define ub(s,x) (upper_bound(all(s),x)-s.begin())

int main(void){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> pos[26];
    rep(i,n){
        pos[s[i]-'a'].push_back(i);
    }
    ll turn = 0, k = -1;
    rep(i,m){
        auto &vec = pos[t[i]-'a'];
        if (vec.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        int index = ub(vec, k);
        if (index == (int)vec.size()) {
            turn++;
            index = ub(vec, -1);
        }
        k = vec[index];
    }
    cout << turn * n + k + 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

void solve() {
    int u;
    cin >> u;
    map<char, int> cnt;
    set<char> used_char;
    rep(i,10000){
        string q, r;
        cin >> q >> r;
        cnt[r[0]]++;
        for (char c : r) {
            used_char.insert(c);
        }
    }

    string res(10, '?');
    assert((int)cnt.size() == 9);
    vector<pair<int, char>> vp;
    for (auto itr : cnt) {
        vp.push_back({itr.second, itr.first});
        used_char.erase(itr.first);
    }
    sort(all(vp), greater<pair<int, char>>());
    rep(i,9){
        res[i+1] = vp[i].second;
    }
    assert((int)used_char.size() == 1);
    res[0] = *used_char.begin();
    cout << res << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    map<int, int> cnt;
    rep(i,n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<int> key, value;
    for (auto itr : cnt) {
        key.push_back(itr.first);
        value.push_back(itr.second);
    }
    if (key.size() == 1) {
        cout << ((key[0] == 0) ? "Yes" : "No") << endl;
    } else if (key.size() > 3 || n % 3 != 0) {
        cout << "No" << endl;
    } else if (key.size() == 2) {
        cout << ((key[0] == 0 && value[0] == n/3) ? "Yes" : "No") << endl;
    } else {
        assert(key.size() == 3);
        cout << (((key[0] ^ key[1] ^ key[2]) == 0 && value[0] == n/3 && value[1] == n/3 && value[2] == n/3) ? "Yes" : "No") << endl;
    }
    return 0;
}

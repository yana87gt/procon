#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    if (n == 2) {
        int a1, a2;
        cin >> a1 >> a2;
        cout << abs(a1-a2) << endl;
        cout << max(a1,a2) << " " << min(a1,a2) << endl;
        return 0;
    }
    vector<int> plus, minus;
    rep(i,n){
        int a;
        cin >> a;
        if (a > 0) plus.push_back(a);
        else minus.push_back(a);
    }
    sort(all(plus),greater<int>());
    sort(all(minus),greater<int>());
    vector<pair<int,int>> res;
    if (minus.empty()) {
        int x = plus.back(); plus.pop_back();
        int y = plus.back(); plus.pop_back();
        assert(x <= y);
        res.push_back({x,y});
        minus.push_back(x-y);
    }
    if (plus.empty()) {
        int x = minus[0];
        int y = minus[1];
        minus.erase(minus.begin(), minus.begin()+2);
        assert(x <= y);
        res.push_back({x,y});
        plus.push_back(x-y);
    }
    assert(!minus.empty() && !plus.empty());
    while (plus.size() > 1) {
        res.push_back({minus[0], plus.back()});
        minus[0] -= plus.back();
        plus.pop_back();
    }
    while (minus.size()) {
        res.push_back({plus[0], minus.back()});
        plus[0] -= minus.back();
        minus.pop_back();
    }
    assert(minus.empty() && plus.size() == 1);
    cout << plus[0] << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}

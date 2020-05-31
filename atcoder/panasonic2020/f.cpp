#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

vector<ll> width = {1LL};

ll solve(ll s1, ll s2, ll l1, ll l2, int level){
    if (level == 0) return abs(l1-l2);
    ll w = width[level-1];
    if (s1/w != s2/w) {
        return abs(s1-s2) + abs(l1-l2);
    } else if (s1/w == 1 && abs(l1/w - l2/w) >= 2) {
        return min(s1%w + s2%w + 2, w*2 - s1%w - s2%w) + abs(l1-l2);
    } else {
        return solve(s1%w, s2%w, l1, l2, level-1);
    }
}

int main(void){
    rep(i,30){
        width.push_back(width.back() * 3LL);
    }
    int Q;
    cin >> Q;
    rep(q,Q){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--,y1--,x2--,y2--;
        if (abs(x1-x2) > abs(y1-y2)) {
            swap(x1,y1), swap(x2,y2);
        }
        cout << solve(x1,x2,y1,y2,30) << endl;
    }
    return 0;
}

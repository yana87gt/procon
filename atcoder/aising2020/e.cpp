#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

struct Camel
{
    ll diff, pos;
    bool operator<(const Camel& rhs) const {
        return diff < rhs.diff;
    }
};


int main(void) {
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        priority_queue<Camel> pqL, pqR;
        ll score = 0;
        rep(i,n) {
            ll k, l, r;
            cin >> k >> l >> r;
            if (l > r) {
                pqL.push({l-r, k-1});
                score += r;
            } else {
                pqR.push({r-l, k});
                score += l;
            }
        }
        
        set<ll> stL;
        rep(i,n) stL.insert(-i);
        while(pqL.size()){
            Camel top = pqL.top(); pqL.pop();
            auto itr = stL.lower_bound(-top.pos);
            if(itr != stL.end()) {
                score += top.diff;
                stL.erase(itr);
            }
        }
        set<ll> stR;
        rep(i,n) stR.insert(i);
        while(pqR.size()) {
            Camel top = pqR.top(); pqR.pop();
            auto itr = stR.lower_bound(top.pos);
            if(itr != stR.end()) {
                score += top.diff;
                stR.erase(itr);
            }
        }
        cout << score << endl;
    }
    return 0;
}

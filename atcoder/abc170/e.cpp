#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n, Q;
    cin >> n >> Q;
    vector<int> y(n+1),rate(n+1);
    using P = pair<int,int>;
    set<P> maxs; // {rate, index}
    vector<set<P>> vs(200010); // [幼稚園] -> {rate, index}
    rep1(i,n){
        int a;
        cin >> a >> y[i];
        rate[i] = a;
        P p = {rate[i], i};
        if (vs[y[i]].empty()) {
            vs[y[i]].insert(p);
            maxs.insert(p);
        } else {
            if (*vs[y[i]].rbegin() < p) {
                maxs.erase(*vs[y[i]].rbegin());
                vs[y[i]].insert(p);
                maxs.insert(p);
            } else {
                vs[y[i]].insert(p);
            }
        }
    }
    rep(q,Q){
        int i,d;
        cin >> i >> d;
        P p = {rate[i], i};
        // iが幼稚園内最強だったら
        if (*vs[y[i]].rbegin() == p) {
            maxs.erase(*vs[y[i]].rbegin());
            vs[y[i]].erase(p);
            if (!vs[y[i]].empty()) {
                maxs.insert(*vs[y[i]].rbegin());
            }
        } else {
            vs[y[i]].erase(p);
        }

        if (vs[d].empty()) {
            vs[d].insert(p);
            maxs.insert(p);
        } else {
            if (*vs[d].rbegin() < p) {
                maxs.erase(*vs[d].rbegin());
                vs[d].insert(p);
                maxs.insert(p);
            } else {
                vs[d].insert(p);
            }
        }
        y[i] = d;
        cout << maxs.begin()->first << endl;
    }
    return 0;
}

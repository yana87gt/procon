#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

template<typename T>
class BIT {
    public:
    int n;
    vector<T> dat; // i: [1,n]

    BIT(int size): n(size+1), dat(vector<T>(n+1)) {}

    void add(int i, T x) {
        while (i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) {
        T ret = 0;
        while (i > 0) {
            ret += dat[i];
            i -= i & -i;
        }
        return ret;
    }

    T range(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

using ll = long long;

vector<ll> h;

// i < j, (v[i] op v[j]) を満たす(i,j)の組を数える
template<typename T>
ll inversion(vector<T> v, string op) {
    assert(op == "<=" || op == ">=" || op == ">" || op == "<");
    if (op == ">=" || op == "<") {
        reverse(v.begin(), v.end());
    }

    ll size = v.size();
    vector<pair<T, int>> vp(size);
    rep(i,size) {
        vp[i] = {v[i],i};
    }
    sort(vp.begin(), vp.end());

    // 小さい順に 1..size の連番を振る
    vector<int> order(size);
    rep(i,size) {
        order[vp[i].second] = i+1;
    }

    // i < j, order[i] <= order[j] の個数を数える
    ll result = 0;
    BIT<ll> bt(size);
    rep(i,size){
        result += bt.sum(order[i]);
        bt.add(order[i], h[i]);
    }

    if (op == ">" || op == "<") {
        return size*(size-1)/2 - result;
    } else {
        return result;
    }
}

int main(void){
    int n;
    cin >> n;
    h.resize(n);
    map<ll,bool> mp;
    bool ng = false;
    rep(i,n) {
        cin >> h[i];
        if (mp[h[i]]) ng = true;
        mp[h[i]] = true;
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }
    reverse(all(h));
    cout << inversion(h, "<=") << endl;
    return 0;
}

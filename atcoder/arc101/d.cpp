#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

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
    BIT<int> bt(size);
    rep(i,size){
        result += bt.sum(order[i]);
        bt.add(order[i], 1);
    }

    if (op == ">" || op == "<") {
        return size*(size-1)/2 - result;
    } else {
        return result;
    }
}

ll n;
vector<int> a;

bool check(int x) {
    vector<int> b(n);
    rep(i,n){
        b[i] = (a[i] >= x ? +1 : -1);
    }
    vector<ll> s(n+1);
    rep(i,n){
        s[i+1] = s[i] + b[i];
    }
    return (n*(n+1)/2 + 1)/2 <= inversion(s, "<=");
}

int main(void) {
    cin >> n;
    a.resize(n);
    vector<int> meds(n);

    rep(i,n){
        cin >> a[i];
        meds[i] = a[i];
    }
    sort(meds.begin(), meds.end());
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l+r)/2;
        if (check(meds[mid])) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << meds[l] << endl;
    return 0;
}

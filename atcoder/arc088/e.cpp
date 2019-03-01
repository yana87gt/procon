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
        bt.add(order[i], 1);
    }

    if (op == ">" || op == "<") {
        return size*(size-1)/2 - result;
    } else {
        return result;
    }
}

int main(void){
    string s;
    cin >> s;
    int n = s.size();

    map<char,int> sum;
    for (char c : s) {
        sum[c]++;
    }
    int odd_alpha = 0;
    for (auto itr : sum) {
        if (itr.second & 1) odd_alpha++;
    }
    if (odd_alpha >= 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> x(n); // s[i] -> sx[j]へ動くとき, x[i] = j
    int ai = 0, ci = (n+1)/2;
    map<char, int> cnt;
    string sa, sc;
    rep(i,n) {
        char c = s[i];
        if ((sum[c]&1) && cnt[c] == sum[c]/2) {
            x[i] = n/2;
        } else if (cnt[c] < sum[c]/2) {
            x[i] = ai++;
            sa += c;
        } else {
            x[i] = ci++;
            sc += c;
        }
        cnt[c]++;
    }

    int m = sa.size();
    map<char, vector<int>> pos;
    rep(i,m) pos[sa[i]].push_back(i);

    cnt.clear();
    reverse(all(sc));
    vector<int> t(m);
    rep(i,m) {
        char c = sc[i];
        t[i] = pos[c][cnt[c]];
        cnt[c]++;
    }

    cout << inversion(x, ">") + inversion(t, ">") << endl;

    return 0;
}

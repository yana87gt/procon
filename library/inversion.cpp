///
/// for vscode snippet
/// prefix: lib-inversion
///

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
ll inversion(vector<T> v, string op = ">") {
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


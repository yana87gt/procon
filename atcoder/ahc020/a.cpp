// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(2);
        cerr << fixed << setprecision(2);
    }
} iosetup;

// -------- START : macro -------- //

#define ll long long
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rep1(i, n) for (long long i = 1; i <= (long long)(n); ++i)
#define len(c) (ll) c.size()
#define all(v) (v).begin(), (v).end()
#define lb(v, x) (lower_bound(all(v), x) - v.begin())
#define ub(v, x) (upper_bound(all(v), x) - v.begin())
#define has(c, x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)), v.end())
#define bit(k) (1LL << (k))
#define INF int(1e9)

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template <class T, class U>
ostream &operator<<(ostream &ost, const pair<T, U> &p) {
    ost << "(" << p.first << ", " << p.second << ")";
    return ost;
}
#define OSTREAM_CONTAINER                   \
    ost << "{";                             \
    for (const auto &t : v) {               \
        if (&t != &*v.begin()) ost << ", "; \
        ost << t;                           \
    }                                       \
    ost << "}";                             \
    return ost;

template <class T>
ostream &operator<<(ostream &ost, const vector<T> &v) {
    OSTREAM_CONTAINER
}
template <class T>
ostream &operator<<(ostream &ost, const set<T> &v) {
    OSTREAM_CONTAINER
}
template <class T, class U>
ostream &operator<<(ostream &ost, const map<T, U> &v) {
    OSTREAM_CONTAINER
}
template <class H>
void recursive_debug(string s, H h) {
    cerr << "\033[33m" << s << " = " << h << endl << "\033[m";
}
template <class H, class... T>
void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << "\033[33m" << s.substr(0, comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma + 1), t...);
}
#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

// -------- END : debug macro -------- //

struct UnionFind {
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n) : par(n), sizes(n, 1) { rep(i, n) par[i] = i; }

    // find root of x
    int find(int x) {
        if (x != par[x]) par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return sizes[find(x)]; }
};

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (abs((n) - (m)) < EPS)
#define ps_edge(PS, i) PS[i], PS[(i + 1) % PS.size()]

namespace std {
bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
}
}  // namespace std

int norm2(Point &a, Point &b) {
    int diff_x = round(a.real() - b.real());
    int diff_y = round(a.imag() - b.imag());
    return diff_x * diff_x + diff_y * diff_y;
}

// -------- END : snippet -------- //

int N, M, K;
// N=100
// 100≤M≤300
// 2000≤K≤5000
int max_norm2 = 0;

struct VirtualEdge {
    int cost, from, to;
    vector<int> eids;
    vector<int> bids;
    VirtualEdge() {}
    ~VirtualEdge() {}
    VirtualEdge(int cost_) : cost(cost_) {}
    VirtualEdge(int cost_, int from_, int to_, vector<int> eids_,
                vector<int> bids_)
        : cost(cost_), from(from_), to(to_), eids(eids_), bids(bids_) {}
    bool operator<(const VirtualEdge &rhs) const { return cost < rhs.cost; }
    bool operator>(const VirtualEdge &rhs) const { return cost > rhs.cost; }
    VirtualEdge operator+(const VirtualEdge &rhs) const {
        vector<int> new_eids = eids, new_bids = bids;
        new_eids.insert(new_eids.end(), all(rhs.eids));
        new_bids.insert(new_bids.end(), rhs.bids.begin() + 1, rhs.bids.end());
        return VirtualEdge(cost + rhs.cost, from, rhs.to, new_eids, new_bids);
    }
};

// bs: broadcaster, rs: residents
vector<Point> bs(100), rs;
vector<int> w;
vector<vector<int>> g(100);
vector<vector<VirtualEdge>> v_edges(100,
                                    vector<VirtualEdge>(100, VirtualEdge(1e9)));

struct STATE {
    vector<int> norm2s;
    vector<bool> use_edge;
};

void output(STATE &state) {
    rep(bi, N) {
        cout << int(ceil(sqrt(state.norm2s[bi]))) << (bi < N - 1 ? " " : "\n");
    }
    rep(ri, M) { cout << state.use_edge[ri] << (ri < M - 1 ? " " : "\n"); }
}

// O(N^2 + )
void connect_edges(STATE &state) {
    state.use_edge = vector<bool>(M);
    priority_queue<VirtualEdge, vector<VirtualEdge>, greater<VirtualEdge>> qu;
    rep(bi1, N) rep(bi2, bi1) {
        if (state.norm2s[bi1] > 0 && (bi2 == 0 || state.norm2s[bi2] > 0)) {
            qu.push(v_edges[bi1][bi2]);
        }
    }
    UnionFind uf(N);
    while (!qu.empty()) {
        VirtualEdge v_edge = qu.top();
        qu.pop();
        if (uf.same(v_edge.from, v_edge.to)) continue;
        uf.unite(v_edge.from, v_edge.to);
        for (int bi : v_edge.bids) {
            if (bi == v_edge.from) continue;
            if (bi == v_edge.to) continue;
            uf.unite(v_edge.from, bi);
            rep(to, N) {
                if (uf.same(bi, to)) continue;
                if (state.norm2s[to] > 0 || uf.size(to) > 1) {
                    qu.push(v_edges[bi][to]);
                }
            }
        }
        for (int ei : v_edge.eids) state.use_edge[ei] = true;
        // output();
    }
}

void init(STATE &state) {
    // input
    cin >> N >> M >> K;
    rs.resize(K);
    vector<bool> reached(K);
    reached.resize(K);
    state.norm2s.resize(N);
    rep(bi, N) {
        double x, y;
        cin >> x >> y;
        bs[bi] = Point(x, y);
    }
    rep(ei_, M) {
        int u, v, weight;
        cin >> u >> v >> weight;
        --u, --v;
        int ei = ei_;
        g[u].push_back(v);
        g[v].push_back(u);
        v_edges[u][v] = VirtualEdge(weight, u, v, {ei}, {u, v});
        v_edges[v][u] = VirtualEdge(weight, v, u, {ei}, {u, v});
        w.push_back(weight);
    }
    rep(k, N) rep(i, N) rep(j, N) {
        if (v_edges[i][j].cost > v_edges[i][k].cost + v_edges[k][j].cost) {
            v_edges[i][j] = v_edges[i][k] + v_edges[k][j];
        }
    }

    // 各住民から見て近い放送局にお世話になる

    // {norm2, {broadcaster index, residents index}}
    vector<pair<int, pair<int, int>>> close_b;
    rep(ri, K) {
        double x, y;
        cin >> x >> y;
        rs[ri] = Point(x, y);

        int min_norm2 = norm2(rs[ri], bs[0]);
        int min_norm2_id = 0;
        rep(bi, N) {
            double nm = norm2(rs[ri], bs[bi]);
            if (min_norm2 > nm) {
                min_norm2 = nm;
                min_norm2_id = bi;
            }
        }
        close_b.push_back({min_norm2, {min_norm2_id, ri}});
        max_norm2 = max(min_norm2, max_norm2);
    }
    sort(all(close_b));
    reverse(all(close_b));
    for (auto &p : close_b) {
        int bi = p.second.first;
        int ri = p.second.second;
        if (reached[ri]) continue;
        state.norm2s[bi] = norm2(rs[ri], bs[bi]);
        rep(rii, K) {
            if (norm2(bs[bi], rs[rii]) <= state.norm2s[bi]) {
                reached[rii] = true;
            }
        }
        assert(reached[ri]);
    }

    connect_edges(state);
}

void modify(STATE &state) {
    // norm2s[bi] > 0 となる 放送局 shrink をランダムに選ぶ
    int shrink_id;
    vector<pair<int, int>> shrink_cand;
    {
        rep(bi, N) {
            if (state.norm2s[bi] > 0) {
                shrink_cand.push_back({state.norm2s[bi], bi});
            }
        }
        sort(all(shrink_cand));
        vector<double> roulette = {0, 0, 0, 0, 0.1, 0.2, 0.3, 0.5, 0.75, 0.99};
        int pos = shrink_cand.size() * roulette[rand() % roulette.size()];
        shrink_id = shrink_cand[pos].second;
    }

    // 放送局 shrink がカバーする住民を距離順に列挙し、
    // indexの 0%, 20%, 40%, 60%, 80% のうちのどれかの距離に合わせてnorm2変更
    // 放送局 shrink から外れた out_rs を列挙
    vector<int> out_rs;
    {
        vector<pair<int, int>> covered_norm2s = {{0, -1}};
        rep(ri, K) {
            int nrm = norm2(bs[shrink_id], rs[ri]);
            if (nrm <= state.norm2s[shrink_id]) {
                covered_norm2s.push_back({nrm, ri});
            }
        }
        sort(all(covered_norm2s));
        vector<double> roulette = {0, 0, 0, 0, 0.2, 0.4, 0.6, 0.8};
        int pos = covered_norm2s.size() * roulette[rand() % roulette.size()];
        state.norm2s[shrink_id] = covered_norm2s[pos].first;
        for (int i = pos + 1; i < (int)covered_norm2s.size(); ++i) {
            if (covered_norm2s[i].first > state.norm2s[shrink_id]) {
                out_rs.push_back(covered_norm2s[i].second);
            }
        }
    }

    // shrink の norm2 は固定にして、
    // out_rs のcloseな放送局(bi',norm2)の大きいものをランダムで選択して適用
    // 入らなくなった点がまだあれば繰り返す
    while (!out_rs.empty()) {
        // 拡大する放送局を列挙
        map<int, int> enlarge_cand;
        for (int ri : out_rs) {
            bool not_out = false;
            int min_norm2 = 1e9;
            int min_norm2_id = -1;
            for (auto p : shrink_cand) {
                int bi = p.second;
                if (bi == shrink_id) continue;
                int nrm2 = norm2(rs[ri], bs[bi]);
                if (nrm2 <= state.norm2s[bi]) {
                    not_out = true;
                    break;
                }
                if (min_norm2 > nrm2) {
                    min_norm2 = nrm2;
                    min_norm2_id = bi;
                }
            }
            if (not_out) continue;
            assert(min_norm2_id != -1);
            enlarge_cand[min_norm2_id] =
                max(enlarge_cand[min_norm2_id], min_norm2);
        }
        if (enlarge_cand.empty()) break;

        // 拡大コストが小さいものを選ぶ
        int min_cost_id = -1;
        int min_cost = 1e9;
        for (auto &itr : enlarge_cand) {
            int bi = itr.first;
            int nrm2 = itr.second;
            if (min_cost > nrm2 - state.norm2s[bi]) {
                min_cost = nrm2 - state.norm2s[bi];
                min_cost_id = bi;
            }
        }
        assert(min_cost_id != -1);
        state.norm2s[min_cost_id] = enlarge_cand[min_cost_id];

        // それでも入っていない住民を列挙
        vector<int> new_out_rs;
        for (int ri : out_rs) {
            if (norm2(rs[ri], bs[min_cost_id]) > state.norm2s[min_cost_id]) {
                new_out_rs.push_back(ri);
            }
        }
        out_rs = new_out_rs;
    }

    connect_edges(state);
    // output(state);
}

double calc_score(STATE &state) {
    double s = 0;
    rep(bi, N) { s += pow(ceil(sqrt(state.norm2s[bi])), 2.0); }
    rep(ri, M) {
        if (state.use_edge[ri]) {
            s += w[ri];
        }
    }
    return round(1e6 * (1 + 1e8 / (s + 1e7)));
}

auto get_time() { return chrono::system_clock::now(); }

double get_elapsed_time(chrono::system_clock::time_point start_time) {
    return chrono::duration_cast<chrono::milliseconds>(get_time() - start_time)
        .count();
}

void simulated_annealing() {
    double start_temp = 50, end_temp = 100, time_limit = 1970, R = 10000;
    auto start_time = get_time();
    STATE state;
    init(state);
    double pre_score = calc_score(state);
    while (true) {
        double elapsed_time = get_elapsed_time(start_time);
        if (elapsed_time > time_limit) break;
        STATE new_state = state;
        modify(new_state);
        double new_score = calc_score(new_state);
        double temp =
            start_temp + (end_temp - start_temp) * elapsed_time / time_limit;
        double prob = exp((new_score - pre_score) / temp);
        debug(elapsed_time, pre_score, new_score, temp, prob);
        if (prob > (rand() % (int)R) / R) {
            debug(pre_score, new_score, new_score - pre_score);
            state = new_state;
            pre_score = new_score;
        }
    }
    output(state);
}

int main(void) {
    simulated_annealing();
    return 0;
}

/*
焼きなまし法の参考:
    - https://gasin.hatenadiary.jp/entry/2019/09/03/162613
    - https://shindannin.hatenadiary.com/entry/2021/03/06/115415
解説:
    - https://simanman.hatenablog.com/entry/2023/06/11/232949
    - https://atcoder.jp/contests/ahc020/editorial/6578
    - https://atcoder.jp/contests/ahc020/editorial/6576


seed1で156万点くらい
visualizerを見るとまだまだ無駄な放送局がある
一回のmodifyが重いので軽くする
[TODO]
* 各放送局から近い順に0~5000までの住民を列挙しておく
* プロファイラを取れるのであれば、どの処理に時間がかかっているのか調べる
* Assertion failed: (min_norm2_id != -1), function modify, file a.cpp, line 337
* P > 5000 を検知する

*/

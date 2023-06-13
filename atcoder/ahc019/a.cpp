// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
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
#define ostream_container                       \
    {                                           \
        ost << "{";                             \
        for (const auto &t : v) {               \
            if (&t != &*v.begin()) ost << ", "; \
            ost << t;                           \
        }                                       \
        ost << "}";                             \
        return ost;                             \
    }
template <class T>
ostream &operator<<(ostream &ost, const vector<T> &v) ostream_container
    template <class T>
    ostream &operator<<(ostream &ost, const set<T> &v) ostream_container
    template <class T, class U>
    ostream &operator<<(ostream &ost, const map<T, U> &v) ostream_container

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

// -------- END : snippet -------- //

using Block = vector<int>;
using BlockPair = vector<Block>;
vector<vector<int>> result(2);

int TIME_LIMIT = 5980;
int D;
int f[2][14][14];
int r[2][14][14];
int c[2][14][14][14];
int t[24][3][3] = {
    {{+1, 0, 0}, {0, +1, 0}, {0, 0, +1}}, {{+1, 0, 0}, {0, -1, 0}, {0, 0, -1}},
    {{+1, 0, 0}, {0, 0, +1}, {0, -1, 0}}, {{+1, 0, 0}, {0, 0, -1}, {0, +1, 0}},
    {{-1, 0, 0}, {0, +1, 0}, {0, 0, -1}}, {{-1, 0, 0}, {0, -1, 0}, {0, 0, +1}},
    {{-1, 0, 0}, {0, 0, -1}, {0, -1, 0}}, {{-1, 0, 0}, {0, 0, +1}, {0, +1, 0}},

    {{0, +1, 0}, {0, 0, +1}, {+1, 0, 0}}, {{0, +1, 0}, {0, 0, -1}, {-1, 0, 0}},
    {{0, +1, 0}, {+1, 0, 0}, {0, 0, -1}}, {{0, +1, 0}, {-1, 0, 0}, {0, 0, +1}},
    {{0, -1, 0}, {0, 0, +1}, {-1, 0, 0}}, {{0, -1, 0}, {0, 0, -1}, {+1, 0, 0}},
    {{0, -1, 0}, {+1, 0, 0}, {0, 0, +1}}, {{0, -1, 0}, {-1, 0, 0}, {0, 0, -1}},

    {{0, 0, +1}, {+1, 0, 0}, {0, +1, 0}}, {{0, 0, +1}, {-1, 0, 0}, {0, -1, 0}},
    {{0, 0, +1}, {0, +1, 0}, {-1, 0, 0}}, {{0, 0, +1}, {0, -1, 0}, {+1, 0, 0}},
    {{0, 0, -1}, {+1, 0, 0}, {0, -1, 0}}, {{0, 0, -1}, {-1, 0, 0}, {0, +1, 0}},
    {{0, 0, -1}, {0, +1, 0}, {+1, 0, 0}}, {{0, 0, -1}, {0, -1, 0}, {-1, 0, 0}},
};

auto get_time() { return chrono::system_clock::now(); }

chrono::system_clock::time_point start_time;
int get_elapsed_time() {
    auto cur_time = get_time();
    int msec =
        chrono::duration_cast<chrono::milliseconds>(cur_time - start_time)
            .count();
    return msec;
}

void init() {
    cin >> D;
    int can_put_num[2] = {0, 0};
    rep(i, 2) {
        rep(z, D) {
            string row;
            cin >> row;
            rep(x, D) f[i][z][x] = row[x] == '1';
        }
        rep(z, D) {
            string row;
            cin >> row;
            rep(y, D) r[i][z][y] = row[y] == '1';
        }
        rep(z, D) rep(y, D) rep(x, D) {
            c[i][x][y][z] = (f[i][z][x] && r[i][z][y] ? 0 : -1);
            if (c[i][x][y][z] == 0) can_put_num[i]++;
        }
        debug(can_put_num[i]);
    }
}

#define index_to_pos(x, y, z, index) \
    int x = (index / D) / D, y = (index / D) % D, z = index % D

inline int pos_to_index(int x, int y, int z) { return x * D * D + y * D + z; }

inline bool out_of_cube(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return true;
    if (x >= D || y >= D || z >= D) return true;
    return false;
}

bool cancel_dfs;

inline void dfs(int x1, int y1, int z1, int x2, int y2, int z2, int dx, int dy,
                int dz, int rotate, Block &b1, Block &b2) {
    if (cancel_dfs) return;
    int cur_x1 = x1 + dx;
    int cur_y1 = y1 + dy;
    int cur_z1 = z1 + dz;
    int cur_x2 =
        x2 + t[rotate][0][0] * dx + t[rotate][0][1] * dy + t[rotate][0][2] * dz;
    int cur_y2 =
        y2 + t[rotate][1][0] * dx + t[rotate][1][1] * dy + t[rotate][1][2] * dz;
    int cur_z2 =
        z2 + t[rotate][2][0] * dx + t[rotate][2][1] * dy + t[rotate][2][2] * dz;
    int index1 = pos_to_index(cur_x1, cur_y1, cur_z1);
    // int index2 = pos_to_index(cur_x2, cur_y2, cur_z2);
    if (out_of_cube(cur_x1, cur_y1, cur_z1)) return;
    if (out_of_cube(cur_x2, cur_y2, cur_z2)) return;
    if (c[0][cur_x1][cur_y1][cur_z1] != 0) return;
    if (c[1][cur_x2][cur_y2][cur_z2] != 0) return;
    if (dz < 0 || (dz == 0 && dy < 0) || (dz == 0 && dy == 0 && dx < 0)) {
        cancel_dfs = true;
        return;
    }
    if (find(all(b1), index1) != b1.end()) return;
    b1.push_back(pos_to_index(cur_x1, cur_y1, cur_z1));
    b2.push_back(pos_to_index(cur_x2, cur_y2, cur_z2));

    int dir[] = {-1, 0, 0, +1, 0, 0};
    rep(i, 6) {
        if (cancel_dfs) return;
        int unit_x = dir[(i + 4) % 6];
        int unit_y = dir[(i + 5) % 6];
        int unit_z = dir[i];
        dfs(x1, y1, z1, x2, y2, z2, dx + unit_x, dy + unit_y, dz + unit_z,
            rotate, b1, b2);
    }
}

bool is_completed() {
    rep(i, 2) {
        rep(z, D) rep(x, D) {
            if (f[i][z][x]) {
                bool ok = false;
                rep(y, D) ok |= c[i][x][y][z] > 0;
                if (!ok) return false;
            }
        }
        rep(z, D) rep(y, D) {
            if (r[i][z][y]) {
                bool ok = false;
                rep(x, D) ok |= c[i][x][y][z] > 0;
                if (!ok) return false;
            }
        }
    }
    return true;
}

class BlockPairQueue {
   public:
    int width;
    map<pair<pair<int, int>, size_t>, BlockPair> mp;
    BlockPairQueue() {}
    ~BlockPairQueue() {}
    BlockPairQueue(int width_) : width(width_) {}

    void push(int score, BlockPair &block_pair) {
        stringstream ss;
        ss << "score:" << score << block_pair;
        mp[{{score, len(block_pair[0]) >= D ? -len(block_pair[0])
                                            : len(block_pair[0])},
            hash<string>()(ss.str())}] = block_pair;
        while (len(mp) > width) {
            mp.erase(mp.begin());
        }
    }

    vector<BlockPair> to_vector() {
        vector<BlockPair> v;
        for (auto &itr : mp) {
            v.push_back(itr.second);
        }
        reverse(all(v));
        return v;
    }

    bool empty() { return mp.empty(); }
};

bool out_of_time = false;
double min_score = 1e4;
int min_score_n = 0;

void back_track(int depth, vector<BlockPair> &decided_block_pairs) {
    if (is_completed()) {
        double score = 0.0;
        for (BlockPair &decided_block_pair : decided_block_pairs) {
            score += 1.0 / double(decided_block_pair[0].size());
        }
        if (min_score > score) {
            debug(min_score, score);
            min_score = score;
            min_score_n = decided_block_pairs.size();
            rep(i, 2) {
                rep(x, D) rep(y, D) rep(z, D) {
                    if (c[i][x][y][z] > 0) {
                        result[i][pos_to_index(x, y, z)] = c[i][x][y][z];
                    } else {
                        result[i][pos_to_index(x, y, z)] = 0;
                    }
                }
            }
        }
        return;
    }

    if (get_elapsed_time() >= TIME_LIMIT) {
        out_of_time = true;
        return;
    }
    if (min_score_n == 0) {
        int k = 0;
        rep(i, 2) {
            rep(x, D) rep(y, D) rep(z, D) {
                if (c[i][x][y][z] > 0) {
                    result[i][pos_to_index(x, y, z)] = c[i][x][y][z];
                } else if (c[i][x][y][z] == -1) {
                    result[i][pos_to_index(x, y, z)] = 0;
                } else {
                    result[i][pos_to_index(x, y, z)] = ++k;
                }
            }
        }
        min_score_n = k;
    }

    int width = depth == 1 ? 10 : depth == 2 ? 10 : depth <= 5 ? 2 : 1;
    if (D == 14) {
        width = 1;
    }
    BlockPairQueue qu(width);
    rep(z1, D) rep(y1, D) rep(x1, D) {
        if (c[0][x1][y1][z1] != 0) continue;
        if (get_elapsed_time() >= TIME_LIMIT) {
            out_of_time = true;
            return;
        }
        if (out_of_time) return;
        rep(rotate, 24) {
            rep(z2, D) rep(y2, D) rep(x2, D) {
                if (c[1][x2][y2][z2] != 0) continue;
                BlockPair block_pair(2);
                cancel_dfs = false;
                dfs(x1, y1, z1, x2, y2, z2, 0, 0, 0, rotate, block_pair[0],
                    block_pair[1]);
                if (cancel_dfs) continue;
                if (depth <= 2 && len(block_pair[0]) <= 2) {
                    continue;
                }

                int point = 0;
                if (D == 14) {
                    point = len(block_pair[0]);
                } else {
                    vector<set<pair<int, int>>> f_set(2), r_set(2);
                    rep(i, 2) {
                        for (int ii : block_pair[i]) {
                            index_to_pos(xx, yy, zz, ii);
                            bool f_ok = true, r_ok = true;
                            rep(yyy, D) {
                                if (c[i][xx][yyy][zz] > 0) {
                                    f_ok = false;
                                    break;
                                }
                            }
                            rep(xxx, D) {
                                if (c[i][xxx][yy][zz] > 0) {
                                    r_ok = false;
                                    break;
                                }
                            }
                            if (f_ok) f_set[i].insert({zz, xx});
                            if (r_ok) r_set[i].insert({zz, yy});
                        }
                    }
                    point = f_set[0].size() + f_set[1].size() +
                            r_set[0].size() + r_set[1].size();
                }

                if (point >= 1) {
                    // sort(all(block_pair[0]));
                    // sort(all(block_pair[1]));
                    qu.push(point, block_pair);
                }
            }
        }
    }

    if (qu.empty()) {
        debug("qu is empty()");
        return;
    }
    vector<BlockPair> cand_block_pairs = qu.to_vector();
    for (BlockPair &block_pair : cand_block_pairs) {
        if (out_of_time) break;
        rep(i, 2) {
            for (auto index : block_pair[i]) {
                index_to_pos(x, y, z, index);
                c[i][x][y][z] = depth;
            }
        }
        decided_block_pairs.push_back(block_pair);
        back_track(depth + 1, decided_block_pairs);
        decided_block_pairs.pop_back();
        rep(i, 2) {
            for (auto index : block_pair[i]) {
                index_to_pos(x, y, z, index);
                c[i][x][y][z] = 0;
            }
        }
    }
}

int main(void) {
    start_time = get_time();
    init();
    rep(i, 2) result[i].resize(D * D * D);

    vector<BlockPair> decided_block_pairs;
    back_track(1, decided_block_pairs);

    cout << min_score_n << endl;
    rep(i, 2) {
        rep(index, D * D * D) {
            cout << result[i][index] << (index < D * D * D - 1 ? " " : "\n");
        }
    }

    auto elapsed_time = get_elapsed_time();
    debug(elapsed_time);
    return 0;
}

/*

[Memo]
* 14^3 = 2744
* キューブの回転は24通りある
* (f1, r1), (f2, r2) それぞれのペアについて配置可能空間 c1, c2 を01で作る
* Twitter:
https://twitter.com/search?q=%23AHC019%20%23visualizer&src=typed_query&f=live
* 枝狩りの力を信じると意外と間に合う

[TODO]
* [done] シルエット完成判定
* [done] とりあえず最大のものを取っていく
* [done]
最大のものだと片方が埋まってしまい、影埋めが意識されないので、サイズじゃなくて影を埋めたマス数でスコアリングする
* [done] 上位K個だけを保存しておくデータ構造を作る -> priority_queue
* [done] backtrack
* [done] スペース枯渇問題を解決
* pointの計算を軽くする
* width の調整

*/
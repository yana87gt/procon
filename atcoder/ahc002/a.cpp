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
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)
#define rep1(i,n) for(long long i = 1; i <= (long long)(n); ++i)
#define len(c) (ll)c.size()
#define all(v) (v).begin(),(v).end()
#define lb(v,x) (lower_bound(all(v),x)-v.begin())
#define ub(v,x) (upper_bound(all(v),x)-v.begin())
#define has(c,x) (c.find(x) != c.end())
#define uniq(v) v.erase(unique(all(v)),v.end())
#define bit(k) (1LL<<(k))
#define INF int(1e9)

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

// -------- END : macro -------- //

// -------- START : debug macro -------- //

template<class T,class U> ostream& operator<<(ostream& ost, const pair<T,U> &p) { ost << "(" << p.first << ", " << p.second << ")"; return ost; }
#define ostream_container { ost << "{"; for(const auto &t : v) { if (&t != &*v.begin()) ost << ", "; ost << t; } ost << "}"; return ost; }
template<class T> ostream& operator<<(ostream &ost, const vector<T> &v) ostream_container
template<class T> ostream& operator<<(ostream &ost, const set<T> &v) ostream_container
template<class T,class U> ostream& operator<<(ostream &ost, const map<T,U> &v) ostream_container

template<class H> void recursive_debug(string s, H h) {
    cerr << "\033[33m" << s << " = " << h << endl << "\033[m";
}
template<class H,class... T> void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << "\033[33m" << s.substr(0,comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma+1), t...);
}
#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

// -------- END : debug macro -------- //

// -------- END : snippet -------- //

/*
DDDDLDLLULDLULLURUUULULDLDDDLDLUUULLDDDLULUULLLULDDDRDRDDLDLLUULUULLLLUUULULL
方針
ポイントは無視で、とにかく長く作ることを考える
踏みたての近くを使う
詰みを作らない方法を考える

条件1: 広場(Square)へのパスが存在する
条件2: なるべく壁を這う（中心からのチェビシェフ距離？）
*/
#define N 50
#define BEAM_SEARCH_WIDTH 500
#define DEPTH 25
#define RANGE 15

int M = 0;
int t[N][N];
int p[N][N];

int DY[4] = {-1, 0, +1, 0};
int DX[4] = {0, +1, 0, -1};

bool is_wall(int y, int x){
    return y < 0 || x < 0 || y >= N || x >= N;
}

int mht_dist(int y1, int x1, int y2, int x2) {
    return abs(y1-y2) + abs(x1-x2);
}

class State{
  public:
    int y, x, score;
    string command;

    vector<bool> painted;
    double benefit;
    int sq_ly, sq_ry, sq_lx, sq_rx;
    // vector<pair<int,int>> path;

    State(int sy, int sx) {
        y = sy;
        x = sx;

        vector<int> widths = {sy, sx, N-1-sy, N-1-sx};
        int max_width = *max_element(all(widths));
        // if (max_width == sy) {
        //     sq_ly = 0, sq_ry = sy-1, sq_lx = 0, sq_rx = N-1;
        // } else if (max_width == sx) {
        //     sq_ly = 0, sq_ry = N-1, sq_lx = 0, sq_rx = sx-1;
        // } else if (max_width == N-1-sy) {
        //     sq_ly = sy+1, sq_ry = N-1, sq_lx = 0, sq_rx = N-1;
        // } else if (max_width == N-1-sx) {
        //     sq_ly = 0, sq_ry = N-1, sq_lx = sx+1, sq_rx = N-1;
        // }
        sq_ly = N/2-1, sq_ry = N/2+1, sq_lx = N/2-1, sq_rx = N/2+1;
        debug(sq_lx, sq_rx, sq_ly, sq_ry);

        int max_t = 0;
        rep(y_,N) rep(x_,N) {
            chmax(max_t, t[y_][x_]);
        }
        painted.resize(max_t+1);
        painted[t[y][x]] = true;
        score = p[y][x];
        benefit = 0;
        update_benefit();
    }

    bool can_put(int y_, int x_) {
        if (is_wall(y_, x_)) return false;
        if (painted[t[y_][x_]]) return false;
        return true;
    }

    State move(int dy, int dx) {
        State next_state = *this;
        int ny = y+dy;
        int nx = x+dx;
        if (dy == -1) next_state.command += "U";
        if (dy == +1) next_state.command += "D";
        if (dx == -1) next_state.command += "L";
        if (dx == +1) next_state.command += "R";
        // if (sq_ly == ny) next_state.sq_ly++;
        // if (sq_ry == ny) next_state.sq_ry--;
        // if (sq_lx == nx) next_state.sq_lx++;
        // if (sq_rx == nx) next_state.sq_rx--;

        next_state.painted[t[ny][nx]] = true;
        next_state.score += p[ny][nx];
        next_state.y = ny;
        next_state.x = nx;
        next_state.update_benefit();
        return next_state;
    }

    void update_benefit() {
        benefit = max(abs(N/2 - x), abs(N/2 - y)) + benefit;
        if (benefit > 0 && !can_reach_square()){
            benefit -= 100000000;
        }
    }

    bool can_reach_square() {
        int my = (sq_ly + sq_ry)/2;
        int mx = (sq_lx + sq_rx)/2;
        map<int,bool> used_t;
        int call_count = 0;
        auto dfs = [&](auto &&f, int cy, int cx, int depth) {
            call_count++;
            if (mht_dist(cy, cx, my, mx) > depth) return false;
            if (depth < 0) return false;
            if (sq_ly <= cy && cy <= sq_ry && sq_lx <= cx && cx <= sq_rx) return true;
            using P = pair<int,int>;
            vector<P> cands;
            used_t[t[cy][cx]] = true;
            rep(i,4) {
                int ny = cy + DY[i];
                int nx = cx + DX[i];
                if (!can_put(ny, nx)) continue;
                if (used_t[t[ny][nx]]) continue;
                cands.push_back({ny, nx});
            }
            sort(all(cands), [&](P &lhs, P &rhs) {
                return mht_dist(lhs.first, lhs.second, my, mx) < mht_dist(rhs.first, rhs.second, my, mx);
            });
            for (P p : cands) {
                if (f(f, p.first, p.second, depth-1)) return true;
            }
            used_t[t[cy][cx]] = false;
            return false;
        };
        int depth_y = (y < sq_ly ? sq_ly - y : sq_ry < y ? y - sq_ry : 0);
        int depth_x = (x < sq_lx ? sq_lx - x : sq_rx < x ? x - sq_rx : 0);
        bool ok = dfs(dfs, y, x, depth_y + depth_x + 3);
        debug(ok, call_count);
        return ok;
    }

    bool operator>(const State &rhs) const {
        return benefit > rhs.benefit;
        // return score > rhs.score;
    }
};

int main(void) {
    int sy, sx;
    cin >> sy >> sx;
    rep(y,N) rep(x,N) {
        cin >> t[y][x];
        chmax(M, t[y][x]);
    }
    rep(y,N) rep(x,N) cin >> p[y][x];

    vector<State> cur_candidates = {State(sy, sx)};
    while (true) {
        vector<State> next_candidates;
        for (State &cur_state : cur_candidates) {
            rep(i,4) {
                if (cur_state.can_put(cur_state.y + DY[i], cur_state.x + DX[i])) {
                    State next_state = cur_state.move(DY[i], DX[i]);
                    if (next_state.can_reach_square()) {
                        next_candidates.push_back(next_state);
                    }
                }
            }
        }
        if (next_candidates.empty()) break;
        sort(all(next_candidates), greater<State>());
        if (len(next_candidates) > BEAM_SEARCH_WIDTH) {
            next_candidates.erase(next_candidates.begin() + BEAM_SEARCH_WIDTH, next_candidates.end());
        }
        cur_candidates = move(next_candidates);
        debug(cur_candidates[0].score, cur_candidates[0].command.size());
        if (len(cur_candidates[0].command) == 3LL) break;
    }
    sort(all(cur_candidates), [](const State &lhs, const State &rhs) { return lhs.score > rhs.score; });
    for (State &state : cur_candidates) {
        debug(state.benefit, state.score);
    }
    cout << cur_candidates[0].command << endl;
    return 0;
}
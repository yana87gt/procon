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
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
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

struct Rectangle {
    int lx,ly,rx,ry;
};

struct Ad {
    int id,x,y,r;
    Rectangle rect;
    double difficult;
    bool operator<(const Ad& rhs) const {
        return r > rhs.r;
    }
};

struct Priority {
    double difficult;
    double inc_point;
    bool operator<(const Priority& rhs) const {
        if (difficult != rhs.difficult) {
            return difficult < rhs.difficult;
        } else {
            return inc_point < rhs.inc_point;
        }
    }
};


int N;
vector<Ad> a;
priority_queue<pair<Priority, Ad>> qu; // 

bool point_in_rect(int x, int y, Rectangle &rect) {
    return rect.lx <= x && x <= rect.rx && rect.ly <= y && y <= rect.ry;
}

// rect1 と rect2 が交差していない かつ
bool cross_2rect(Rectangle &rect1, Rectangle &rect2) {
    return (
        point_in_rect(rect1.lx, rect1.ly, rect2) or
        point_in_rect(rect1.rx, rect1.ly, rect2) or
        point_in_rect(rect1.lx, rect1.ry, rect2) or
        point_in_rect(rect1.rx, rect1.ry, rect2) or
        point_in_rect(rect2.lx, rect2.ly, rect1) or
        point_in_rect(rect2.rx, rect2.ly, rect1) or
        point_in_rect(rect2.lx, rect2.ry, rect1) or
        point_in_rect(rect2.rx, rect2.ry, rect1)
    );
}

bool valid_area(Rectangle &rect) {
    return 0 <= rect.lx and rect.rx <= 10000 and 0 <= rect.ly and rect.ry <= 10000;
}

int calc_area(Rectangle &rect) {
    return (rect.rx - rect.lx) * (rect.ry - rect.ly);
}

double calc_point(Ad &ad) {
    // if (!point_in_rect(ad.x, ad.y, ad.rect)) return 0;
    int s = (ad.rect.rx - ad.rect.lx) * (ad.rect.ry - ad.rect.ly);
    return 1.0 - pow(1.0 - (double) min(ad.r, s) / (double) max(ad.r, s), 2.0);
}

int min_dist_to_corner(Rectangle &rect) {
    return min({rect.lx + rect.ly, rect.lx + 10000 - rect.ry, 10000 - rect.rx + rect.ly, 20000 - rect.rx - rect.ry});
}

// TODO
// 1. 最も外壁にちかい方向
// 2. 2番目に壁に近い方向
// 角に近い方向にとりあえず伸ばして、次に
double calc_inc_point(Ad &new_ad) {
    return (calc_point(new_ad) - calc_point(a[new_ad.id])) / min_dist_to_corner(new_ad.rect);
}

void push_extend(Ad ad, int dx, int dy) {
    Ad ex_ad = ad;
    if (dx < 0) ex_ad.rect.lx += dx;
    if (dx > 0) ex_ad.rect.rx += dx;
    if (dy < 0) ex_ad.rect.ly += dy;
    if (dy > 0) ex_ad.rect.ry += dy;
    if (!valid_area(ex_ad.rect)) return;
    rep(i,N) {
        if (ad.id == i) continue;
        if (cross_2rect(ex_ad.rect, a[i].rect)) return;
    }
    double inc_point = calc_inc_point(ex_ad);
    if (inc_point > 0) qu.push({{ad.difficult, inc_point}, ex_ad});
}

double high_score = 0;
vector<Ad> high_score_set;

void update_sum_point() {
    double sum_point = 0;
    rep(i,N) {
        debug(calc_point(a[i]), a[i].r, calc_area(a[i].rect), i);
        sum_point += calc_point(a[i]);
    }
    sum_point /= N;
    if (high_score < sum_point) {
        high_score = sum_point;
        high_score_set = a;
    }
    debug(sum_point);
}

int main(void) {
    cin >> N;
    a.resize(N);
    rep(i,N) {
        a[i].id = i;
        cin >> a[i].x >> a[i].y >> a[i].r;
        a[i].rect.lx = a[i].x;
        a[i].rect.rx = a[i].x + 1;
        a[i].rect.ly = a[i].y;
        a[i].rect.ry = a[i].y + 1;
        a[i].difficult = 0;
    }

    // 単純に rが低いやつからやる？
    rep(i,N) {
        push_extend(a[i], -1, 0);
        push_extend(a[i], +1, 0);
        push_extend(a[i], 0, -1);
        push_extend(a[i], 0, +1);
    }
    auto run_greedy = [&](){
        while (!qu.empty()) {
            auto top = qu.top(); qu.pop();
            Ad new_ad = top.second;
            double inc_point = top.first.inc_point;
            // 既に拡張をしている（この方法で調べられているかは若干不安）
            if (abs(calc_inc_point(new_ad) - inc_point) > 1e-9) continue;

            // 他の長方形の拡張によってこの候補がinvalid
            bool ng = false;
            rep(i,N) {
                if (new_ad.id == i) continue;
                if (cross_2rect(new_ad.rect, a[i].rect)) ng = true;
            }
            if (ng) continue;

            a[new_ad.id] = new_ad;
            push_extend(new_ad, -1, 0);
            push_extend(new_ad, +1, 0);
            push_extend(new_ad, 0, -1);
            push_extend(new_ad, 0, +1);
        }
        update_sum_point();
    };

    // 1回目
    run_greedy();

    {
        rep(i,N) {
            double point = calc_point(a[i]);
            if (calc_point(a[i]) > 0.7) continue;
            a[i].rect.lx = a[i].x;
            a[i].rect.rx = a[i].x + 1;
            a[i].rect.ly = a[i].y;
            a[i].rect.ry = a[i].y + 1;
            priority_queue<pair<int,int>> far_qu;
            rep(j,N) {
                if (i == j) continue;
                far_qu.push({abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y), j});
            }
            while (!far_qu.empty()) {
                auto top = far_qu.top();
                int j = top.second;
                far_qu.pop();
                while (a[i].x <= a[j].x && a[j].rect.rx + 1 > 10000) {
                    Ad new_ad = a[j];
                    new_ad.rect.lx += 1;
                    new_ad.rect.rx += 1;
                    bool ng = false;
                    rep(k,N) {
                        if (i == k || j == k) continue;
                        if (cross_2rect(new_ad.rect, a[j].rect)) {
                            ng = true;
                            break;
                        }
                    }
                    if (ng) break;
                    a[j] = new_ad;
                }
                while (a[i].x >= a[j].x && a[j].rect.lx - 1 < 0) {
                    Ad new_ad = a[j];
                    new_ad.rect.lx -= 1;
                    new_ad.rect.rx -= 1;
                    bool ng = false;
                    rep(k,N) {
                        if (i == k || j == k) continue;
                        if (cross_2rect(new_ad.rect, a[j].rect)) {
                            ng = true;
                            break;
                        }
                    }
                    if (ng) break;
                    a[j] = new_ad;
                }
                while (a[i].y <= a[j].y && a[j].rect.ry + 1 > 10000) {
                    Ad new_ad = a[j];
                    new_ad.rect.ly += 1;
                    new_ad.rect.ry += 1;
                    bool ng = false;
                    rep(k,N) {
                        if (i == k || j == k) continue;
                        if (cross_2rect(new_ad.rect, a[j].rect)) {
                            ng = true;
                            break;
                        }
                    }
                    if (ng) break;
                    a[j] = new_ad;
                }
                while (a[i].y >= a[j].y && a[j].rect.ly - 1 < 0) {
                    Ad new_ad = a[j];
                    new_ad.rect.ly -= 1;
                    new_ad.rect.ry -= 1;
                    bool ng = false;
                    rep(k,N) {
                        if (i == k || j == k) continue;
                        if (cross_2rect(new_ad.rect, a[j].rect)) {
                            ng = true;
                            break;
                        }
                    }
                    if (ng) break;
                    a[j] = new_ad;
                }
            }
            push_extend(a[i], -1, 0);
            push_extend(a[i], +1, 0);
            push_extend(a[i], 0, -1);
            push_extend(a[i], 0, +1);
            run_greedy();
        }

    }
    // for (int try_num = 2; try_num <= 4; try_num++) {
    //     vector<bool> reset(N);
    //     rep(i,N) {
    //         double point = calc_point(a[i]);
    //         if (calc_point(a[i]) < 0.7) {
    //             a[i].difficult = 1 - point;
    //             Rectangle ex_rect = a[i].rect;
    //             ex_rect.lx -= 1;
    //             ex_rect.ly -= 1;
    //             ex_rect.rx -= 1;
    //             ex_rect.ry -= 1;
    //             rep(j,N) {
    //                 if (i == j) continue;
    //                 if (cross_2rect(ex_rect, a[j].rect)) {
    //                     reset[j] = true;
    //                 }
    //             }
    //             reset[i] = true;
    //         }
    //     }
    //     rep(i,N) {
    //         if (reset[i]) {
    //             a[i].rect.lx = a[i].x;
    //             a[i].rect.rx = a[i].x + 1;
    //             a[i].rect.ly = a[i].y;
    //             a[i].rect.ry = a[i].y + 1;
    //             push_extend(a[i], -1, 0);
    //             push_extend(a[i], +1, 0);
    //             push_extend(a[i], 0, -1);
    //             push_extend(a[i], 0, +1);
    //         }
    //     }

    //     // try_num 回目
    //     run_greedy();
    // }

    // output
    rep(i,N) {
        printf("%d %d %d %d\n",
            high_score_set[i].rect.lx,
            high_score_set[i].rect.ly,
            high_score_set[i].rect.rx,
            high_score_set[i].rect.ry
        );
    }

    return 0;
}

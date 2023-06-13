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


bool simulation(int P, int W, int n) {
    static std::random_device rnd;
    static mt19937 mt(rnd());
    static std::uniform_int_distribution<int> rand(1,100);
    int money = 0;
    for (int i = 0; i < n; i++) {
        int rand_result = rand(mt);
        if (rand_result <= P) {
            money += W;
        }
        money--;
    }
    return money > 0;
}

#define M_MAX 105
#define TRY_MAX 6500

int solve(int P, int W) {
    if (P == 0) {
        return -1;
    } else if (W <= 1) {
        return -1;
    } else if (P == 50 && W == 2) {
        return -1;
    } else if (P >= 51) {
        return -2;
    } else if (P * (W-1) >= 100) {
        return -2;
    }
    // assert(false);
    int ans = -1;
    for (int m = 1; m <= M_MAX; m++) {
        int win = 0;
        for (int try_num = 0; try_num < TRY_MAX; try_num++) {
            if (simulation(P, W, W*m-1)) win++;
        }
        if (win > TRY_MAX - win) {
            ans = max(ans, W*m-1);
        }
    }
    if (ans == W*M_MAX-1) ans = -2;
    return ans;
}

int main(void) {
    // int P, W;
    // cin >> P >> W;
    // cout << solve(P, W) << endl;
    for (int P = 0; P <= 100; P++) {
        for (int W = 0; W <= 100; W++) {
            cout << P << " " << W << " " << solve(P, W) << endl;
        }
    }
    return 0;
}

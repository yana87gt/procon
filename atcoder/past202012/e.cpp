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

vector<string> rot(vector<string>& m){
    int nrow = m.size(), ncol = m[0].size();
    vector<string> m2(ncol, string(nrow, '?'));
    rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
    return m2;
}

int main(void) {
    int Y, X;
    cin >> Y >> X;
    vector<string> s(Y), t(Y);
    rep(y,Y) cin >> s[y];
    rep(y,Y) cin >> t[y];

    int M = max(Y,X);
    {
        rep(y,Y) s[y] = string(M, '.') + s[y] + string(M, '.');
        vector<string> space(M, string(M+X+M, '.'));
        s.insert(s.begin(), space.begin(), space.end());
        s.insert(s.end(), all(space));
    }
    
    vector<string> tt[4];
    tt[0] = t;
    rep(i,3) tt[i+1] = rot(tt[i]);
    rep(deg, 4) {
        rep(sy, M+Y)rep(sx, M+X) {
            bool ng = false;
            int TY = tt[deg].size(), TX = tt[deg][0].size();
            rep(dy, TY)rep(dx, TX) {
                if (tt[deg][dy][dx] == '.') continue;
                assert(tt[deg][dy][dx] == '#');
                if (sy+dy < M || sx+dx < M || M+Y <= sy+dy || M+X <= sx+dx) ng = true;
                if (s[sy+dy][sx+dx] == '#') ng = true;
            }
            if (!ng) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}

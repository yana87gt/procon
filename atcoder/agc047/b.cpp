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

#define B1 100000007
#define B2 9999999999999937
#define C1 2147483647
#define C2 92709568269121

ll rolling_hash(string const& S, ll b1, ll b2) {
    ll res = 1, b_n = 1;
    rep(i, S.size()){
        res = (res + S[i]*b_n) % b2;
        b_n = b_n * b1 % b2;
    }
    return res;
}

// -------- END : snippet -------- //


int main(void) {
    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i,n) cin >> vs[i];
    sort(all(vs), [](const string &lhs, const string &rhs){ return lhs.size() < rhs.size(); });

    map<pair<ll, ll>, map<char, ll>> mp;
    // mp[<hash1, has2>][alpha] = count
    ll res = 0;
    rep(i,n) {
        string &s = vs[i];
        reverse(all(s));

        // counting
        ll hash1 = 1, b_n1 = 1;
        ll hash2 = 1, b_n2 = 1;
        map<char, ll> expected;
        rep(k, s.size()) {
            if (has(mp,make_pair(hash1, hash2))) {
                for (auto itr : mp[make_pair(hash1, hash2)]) {
                    expected[itr.first] += itr.second;
                }
            }
            res += expected[s[k]];
            expected.erase(s[k]);

            hash1 = (hash1 + s[k]*b_n1) % B2;
            b_n1 = b_n1 * B1 % B2;
            hash2 = (hash2 + s[k]*b_n2) % C2;
            b_n2 = b_n2 * C1 % C2;
        }
        res += expected[s.back()];

        // indexing
        char last = s.back();
        s.pop_back();
        mp[make_pair(rolling_hash(s, B1, B2), rolling_hash(s, C1, C2))][last]++;
    }
    cout << res << endl;
    return 0;
}

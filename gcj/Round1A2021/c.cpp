// -------- START : snippet -------- //

#include <bits/stdc++.h>
using namespace std;


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

string reverse_ans(string ans) {
    string rev;
    rep(i, ans.size()) {
        if (ans[i] == 'F') rev += "T";
        else if (ans[i] == 'T') rev += "F";
        else assert(false);
    }
    return rev;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<string> A(N);
    vector<int> S(N);
    rep(i,N) {
        cin >> A[i] >> S[i];
    }
    rep(i,N) {
        if (S[i] < (Q+1)/2) {
            A[i] = reverse_ans(A[i]);
            S[i] = Q - S[i];
        }
    }
    int high_id = 0;
    rep(i,N) {
        if (S[high_id] < S[i]) {
            high_id = i;
        }
    }
    cout << A[high_id] << " " << S[high_id] << "/1" << endl;
}

int main(void) {
    int T;
    cin >> T;
    rep(testcase, T){
        cout << "Case #" << testcase + 1 << ": ";
        solve();
    }
    return 0;
}

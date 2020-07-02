
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef int ll;

#define debug(...) recursive_debug(#__VA_ARGS__, __VA_ARGS__)

void recursive_debug(string) { cerr << endl; }

template<class H,class... T>
void recursive_debug(string s, H h, T... t) {
    int comma = s.find(',');
    cerr << s.substr(0,comma) << " = " << h << ", ";
    recursive_debug(s.substr(comma+1), t...);
}

template<class T,class U>
ostream& operator<<(ostream& ost, const pair<T,U> &p) {
    ost << "(" << p.first << ", " << p.second << ")";
    return ost;
}

template<class T>
ostream& operator<<(ostream &ost, const vector<T> &v) {
    ost << "[";
    for(T t : v) ost << t << ",";
    ost << "]";
    return ost;
}

struct State {
    ll score;
    vector<int> types;
    bool operator<(const State& rhs) const {
        return (score < rhs.score);
    }
    bool operator>(const State& rhs) const {
        return (score > rhs.score);
    }
};


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D, M = 26;
    cin >> D;
    vector<ll> c(M);
    rep(i,M) cin >> c[i];
    vector<vector<ll>> s(D, vector<ll>(M));
    rep(d,D) rep(i,M) cin >> s[d][i];

    set<State> cur_states = {{0, {}}};
    size_t SIZE = 1150;

    rep(d,D) {
        set<State> nxt_states;
        for (auto &cur_itr : cur_states) {
            const State state = cur_itr;
            vector<int> last(M, -1);
            rep(i,state.types.size()) {
                last[state.types[i]] = i;
            }
            ll minus_score = 0;
            rep(i,M) {
                minus_score -= c[i] * (d - last[i]);
            }
            rep(i,M) {
                State nxt_state {
                    state.score + s[d][i] + minus_score + c[i] * (d - last[i]),
                    state.types
                };
                nxt_state.types.push_back(i);
                
                nxt_states.insert(nxt_state);
                if (nxt_states.size() > SIZE) {
                    nxt_states.erase(nxt_states.begin());
                }
            }
        }

        cur_states = std::move(nxt_states);
    }

    for (int t : cur_states.begin()->types) {
        cout << t+1 << endl;
    }
    debug(cur_states.begin()->score);

    return 0;
}

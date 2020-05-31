#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
#define ub(s,x) (upper_bound(all(s),x)-s.begin())
#define uniq(a) a.erase(unique(all(a)),a.end())
#define bit(k) (1LL<<(k))
const int INF = 1e9;

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }



void solve() {
    int n,k;
    cin >> n >> k;
    int a[50][50] = {};
    set<int> cand[50];
    rep(x,n)rep1(i,n)cand[x].insert(i);
    rep(y,n)rep(x,n){
        if (y < k%n) {
            a[y][x] = (k/n + x - y + n) % n + 1;
            cand[x].erase(a[y][x]);
        } else {
            a[y][x] = (k/n + x - y + n*2 - 1) % n + 1;
            cand[x].erase(a[y][x]);
        }
    }
    if (a[0][0] == a[n-1][0] && a[0][n-1] == a[n-1][n-1]) {
        rep1(x,n-1){
            cand[x].insert(a[0][x]);
            a[0][x] = 0;
        }
        rep(x,n-1){
            cand[x].insert(a[n-1][x]);
            a[n-1][x] = 0;
        }
        cand[0].erase(a[0][0]);
        cand[n-1].erase(a[n-1][n-1]);

        set<int> used1 = {a[0][0]}, used2 = {a[n-1][n-1]};
        a[n-1][0] = *cand[0].begin();
        a[0][n-1] = *cand[n-1].begin();
        if (used1.find(a[0][n-1]) != used1.end() || used2.find(a[n-1][0]) != used2.end()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        used1.insert(a[0][n-1]);
        used2.insert(a[n-1][0]);
        rep(x,n) print(cand[x]);

    }
    // }
    // rep(y,k%n){
    //     a[y][y] = k/n+1;
    //     rep(x,n){

    //     }
    // }

    // int rem = k-n;
    // set<int> col[50];
    // rep(i,n){
    //     a[i][i] = min(rem,n-1) + 1;
    //     rem -= min(rem,n-1);
    //     col[i].insert(a[i][i]);
    // }
    // rep(y,n){
    //     set<int> cand;
    //     rep(x,n) cand.insert(x+1);
    //     cand.erase(a[y][y]);
    //     rep(x,n){
    //         if (a[y][x]) continue;
    //         bool found = false;
    //         for (int c : cand) {
    //             if (col[x].find(c) == col[x].end()) {
    //                 a[y][x] = c;
    //                 col[x].insert(c);
    //                 cand.erase(c);
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if(!found) {
    //             cout << "IMPOSSIBLE" << endl;
    //             return;
    //         }
    //     }
    // }
    cout << "POSSIBLE" << endl;
    rep(y,n) rep(x,n) cout << a[y][x] << (x < n-1 ? " " : "\n");
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}

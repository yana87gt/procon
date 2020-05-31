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

using bs = bitset<20>;

vector<bs> make_path(int k) {
    if (k == 0) return {0,1};
    vector<bs> v = make_path(k-1);
    int m = v.size();
    rep(i,m){
        bs t = v[m-1-i];
        t[k] = 1;
        v.push_back(t);
    }
    return v;
}

bs swap_bit(bs x, int k){
    swap(x[0],x[k]);
    // bool bit_0 = x[0];
    // bool bit_k = x[k];
    // x[0] = bit_k;
    // x[k] = bit_0;
    return x;
}



// 1101001 -> 1111000 
// 1111001 -> 1111001
//   ^   ^      ^   ^

int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    vector<bool> visited(1<<n);
    if (__builtin_popcount(a^b) != 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<bs> path = make_path(n-1);
    int k = -1;
    bs bs_a(a), bs_b(b);
    rep(i,n){
        if (bs_a[i] != bs_b[i]) {
            k = i;
            bs_a = swap_bit(bs_a, k);
            bs_b = swap_bit(bs_b, k);
            break;
        }
    }
    assert(k != -1);


    rep(i,1<<n){
        if (path[i] == a) {

        } 
    }
    // int cur = a;
    // cout << cur;
    // int cnt = 0;
    // while (cnt+1 < 1<<n) {
    //     visited[cur] = true;
    //     rep(k,n){
    //         int to = cur^bit(k);
    //         if (to == b && cnt < 1<<n) continue;
    //         if (!visited[to]) {
    //             cur = to;
    //             break;
    //         }
    //     }
    //     cnt++;
    //     cout << " " << cur;
    // }
    // cout << endl;
    return 0;
}

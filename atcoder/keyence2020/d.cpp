#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
const int INF = 1e9;

int mergecount(vector<int> &a) {
    int count = 0;
    int n = a.size();
    rep(i,n) rep(j,i) if(a[j]>a[i]) ++count;
    return count;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int res = INF;
    rep(mask, 1<<n){
        using P = pair<int,int>;
        vector<P> even, odd;
        rep(i,n){
            bool is_back = mask & bit(i);
            if ((i&1)^is_back) {
                odd.push_back({is_back ? b[i] : a[i], i});
            } else {
                even.push_back({is_back ? b[i] : a[i], i});
            }
        }
        if ((int)odd.size() != n/2) continue;
        if(__builtin_popcount(mask) & 1) continue;

        sort(all(even));
        sort(all(odd));
        {
            bool ng = false;
            rep(i,n-1){
                if (i % 2 == 0) {
                    if (even[i/2].first > odd[i/2].first) ng = true;
                } else {
                    if (odd[i/2].first > even[(i+1)/2].first) ng = true;
                }
            }
            if (ng) continue;
        }

        vector<int> v;
        rep(i,n){
            v.push_back((i&1) ? odd[i/2].second : even[i/2].second);
        }
        res = min(res, mergecount(v));
    }
    cout << (res == INF ? -1 : res) << endl;
    return 0;
}

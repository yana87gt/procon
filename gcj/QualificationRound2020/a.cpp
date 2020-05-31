#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(y,n){
        a[y].resize(n);
        rep(x,n) cin >> a[y][x];
    }

    int k = 0, cnt1 = 0, cnt2 = 0;
    rep(i,n) k += a[i][i];
    rep(y,n) {
        set<int> st;
        rep(x,n) st.insert(a[y][x]);
        if ((int)st.size() < n) cnt1++;
    }
    rep(x,n) {
        set<int> st;
        rep(y,n) st.insert(a[y][x]);
        if ((int)st.size() < n) cnt2++;
    }
    printf("%d %d %d\n", k, cnt1, cnt2);
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

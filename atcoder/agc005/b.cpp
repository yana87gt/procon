#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> pos(n+1);
    rep1(i,n) {
        int a;
        cin >> a;
        pos[a] = i;
    }
    set<ll> st = {0, n+1};
    ll res = 0;
    rep1(i,n) {
        st.insert(pos[i]);
        ll l = *(--st.find(pos[i]));
        ll r = *(++st.find(pos[i]));
        res += (pos[i]-l)*(r-pos[i])*i;
    }
    cout << res << endl;
    return 0;
}

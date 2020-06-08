#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> yp(N), xp(N);
    rep(i,N) {
        yp[i] = i*N;
        xp[i] = i;
    }

    rep(q,Q){
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int a,b;
            cin >> a >> b;
            a--, b--;
            swap(yp[a], yp[b]);
        } else if (q_type == 2) {
            int a,b;
            cin >> a >> b;
            a--, b--;
            swap(xp[a], xp[b]);
        } else if (q_type == 3) {
            swap(xp, yp);
        } else {
            int a,b;
            cin >> a >> b;
            a--, b--;
            cout << yp[a] + xp[b] << endl;
        }
    }
    return 0;
}

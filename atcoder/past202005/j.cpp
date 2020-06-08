#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i,m) {
        int a;
        cin >> a;
        auto itr = upper_bound(all(v), -a);
        if (itr == v.end()) {
            cout << -1 << endl;
        } else {
            int pos = itr - v.begin();
            v[pos] = -a;
            cout << pos + 1 << endl;
        }
    }

    return 0;
}

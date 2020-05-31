#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int res = 0;
    rep(i,n){
        int sum = c;
        rep(j,m){
            int a;
            cin >> a;
            sum += a*b[j];
        }
        if (sum > 0) res++;
    }
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 1e9;

int main(void){
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    int res = INF;
    rep(t,n+1){
        int sumA = 0, sumB = 0;
        rep(i,n){
            if (i < t) sumA += w[i];
            else sumB += w[i];
        }
        res = min(res, abs(sumA - sumB));
    }
    cout << res << endl;
    return 0;
}

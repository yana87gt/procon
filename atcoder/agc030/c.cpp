#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int K;
    cin >> K;
    if (K == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    int n = 2*ceil(K/4.0);
    vector<vector<int>> c(n);
    rep(y,n){
        c[y].resize(n);
        rep(x,n){
            if (y%2 == 0) {
                c[y][x] = (y+x)%n;
            } else {
                c[y][x] = n + (y+x)%n;
                if (c[y][x] > K - 1) {
                    c[y][x] -= n;
                }
            }
        }
    }
    cout << n << endl;
    rep(y,n){
        rep(x,n){
            cout << c[y][x]+1 << (x < n-1 ? " " : "\n");
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, m, k;
    cin >> n >> k >> m;
    int sum = 0;
    rep(i,n-1){
        int a;
        cin >> a;
        sum += a;
    }
    rep(i,k+1){
        if (sum+i >= m*n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x = 0;
    rep(i,n){
        if (a[i] == x+1){
            x++;
        }
    }
    cout << (x == 0 ? -1 : n - x) << endl;
    return 0;
}

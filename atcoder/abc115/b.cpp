#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    int sum = 0;
    int mx = 0;
    rep(i,n) {
        int p;
        cin >> p;
        sum += p;
        mx = max(mx, p);
    }
    cout << sum - mx/2 << endl;
    return 0;
}

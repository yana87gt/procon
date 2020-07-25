#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void) {
    int n;
    cin >> n;
    int cnt = 0;
    rep(i,n) {
        int a;
        cin >> a;
        if ((i%2==0) && (a%2==1)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

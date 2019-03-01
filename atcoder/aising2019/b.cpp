#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    int cnt[3] = {};
    rep(i,n) {
        int p;
        cin >> p;
        if (p <= a) cnt[0]++;
        else if (p <= b) cnt[1]++;
        else cnt[2]++;
    }
    cout << min({cnt[0], cnt[1], cnt[2]}) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    int cnt = 0, res = 0, pre = 0;
    rep(i,n) {
        int cur;
        cin >> cur;
        if (pre >= cur) cnt++;
        else cnt = 0;
        res = max(res, cnt);
        pre = cur;
    }
    cout << res << endl;
    return 0;
}

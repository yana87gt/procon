#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    int cnt = 0, x = 0, y = 0, z = 0;
    rep(i,n){
        string s;
        cin >> s;
        int m = s.size();
        rep(j,m-1){
            if (s[j] == 'A' && s[j+1] == 'B'){
                cnt++;
            }
        }
        if (s[0] == 'B' && s.back() == 'A') {
            y++;
        } else if (s.back() == 'A') {
            x++;
        } else if (s[0] == 'B') {
            z++;
        }
    }
    if (y >= 1) {
        cnt += y-1;
        if (x) {
            x--;
            cnt ++;
        }
        if (z) {
            z--;
            cnt ++;
        }
    }
    cnt += min(x,z);
    cout << cnt << endl;

    return 0;
}

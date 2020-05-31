#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    rep(i,n-2){
        if (s.substr(i,3) == "ABC") {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    rep(i,n) {
        if ('0'+(i%2) == s[i]) cnt1++;
        if ('0'+(i%2) != s[i]) cnt2++;
    }
    cout << min(cnt1,cnt2) << endl;
    return 0;
}

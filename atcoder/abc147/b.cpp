#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i,n/2){
        if(s[i] != s[n-1-i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

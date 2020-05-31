#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int sum = 0;
    int able = 0;
    rep(i,n-1){
        if (s[i] == s[i+1]) sum++;
        else able++;
    }
    cout << sum + min(able, k*2) << endl;
    return 0;
}

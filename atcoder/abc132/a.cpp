#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    string s;
    cin >> s;
    sort(all(s));
    cout << ((s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) ? "Yes" : "No") << endl;
    return 0;
}

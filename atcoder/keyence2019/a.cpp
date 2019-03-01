#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    string s;
    rep(i,4) {
        char c;
        cin >> c;
        s += c;
    }
    sort(all(s));
    cout << ((s=="1479") ? "YES" : "NO") << endl;
    return 0;
}

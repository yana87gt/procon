#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    set<string> s;
    rep(i,n) {
        string a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}
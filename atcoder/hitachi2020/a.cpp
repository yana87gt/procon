#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool ng = false;
    if (n&1) ng = true;
    rep(i,n/2){
        if (s.substr(i*2, 2) != "hi") ng = true;
    }
    cout << (ng ? "No" : "Yes") << endl;
}
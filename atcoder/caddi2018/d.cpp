#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    bool win = false;
    rep(i,n) {
        int a;
        cin >> a;
        if (a&1) win = true;
    }
    cout<<((win) ? "first" : "second")<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    string a,b,c;
    cin >> n >> a >> b >> c;
    int res = 0;
    rep(i,n){
        set<char> st = {a[i], b[i], c[i]};
        res += st.size() - 1;
    }
    cout << res << endl;
    return 0;
}

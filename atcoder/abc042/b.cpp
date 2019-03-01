#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    sort(all(s));
    rep(i,n) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}

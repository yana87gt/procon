#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout << ((h <= accumulate(all(a),0)) ? "Yes" : "No") << endl;
    return 0;
}

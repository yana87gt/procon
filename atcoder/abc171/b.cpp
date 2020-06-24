#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    cout << accumulate(p.begin(), p.begin() + k, 0) << endl;
    return 0;
}

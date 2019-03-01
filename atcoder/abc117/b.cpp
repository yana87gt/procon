#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = accumulate(all(a),0);
    int max = *max_element(all(a));
    cout << ((sum - max > max) ? "Yes" : "No") << endl;
    return 0;
}

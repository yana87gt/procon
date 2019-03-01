#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
const int INF = 1e9;

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(all(h));
    int d = INF;
    rep(i,n-k+1){
        d = min(d, h[i+k-1]-h[i]);
    }
    cout << d << endl;
    return 0;
}

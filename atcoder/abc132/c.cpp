#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n){
        cin >> d[i];
    }
    sort(all(d));
    cout << d[n/2] - d[n/2-1] << endl;
    return 0;
}

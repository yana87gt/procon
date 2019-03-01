#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int a[5];
    rep(i,5){
        cin >> a[i];
    }
    vector<int> sum;
    rep(i,5)rep(j,i)rep(k,j){
        sum.push_back(a[i]+a[j]+a[k]);
    }
    sort(all(sum),greater<int>());
    cout << sum[2] << endl;
    return 0;
}

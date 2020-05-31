#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n, k;
    cin >> n >> k;
    vector<double> r(n);
    rep(i,n) cin >> r[i];
    double rate = 0;
    sort(all(r), greater<double>());
    rep(i,k){
        rate = (rate+r[k-1-i])/2;
    }
    printf("%.10f\n", rate);
    return 0;
}

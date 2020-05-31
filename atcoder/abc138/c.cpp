#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i,n){
        cin >> v[i];
    }
    sort(all(v));
    double x = v[0];
    rep1(i,n-1){
        x = (x+v[i])/2.0;
    }
    printf("%.10f\n", x);
    return 0;
}

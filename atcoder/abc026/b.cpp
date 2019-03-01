#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<double> r(n);
    rep(i,n) cin >> r[i];
    sort(all(r), greater<double>());
    double area = 0;
    rep(i,n) {
        if (i%2==0) {
            area += pow(r[i],2);
        } else {
            area -= pow(r[i],2);
        }
    }
    printf("%.10f\n", area * acos(-1));

    return 0;
}

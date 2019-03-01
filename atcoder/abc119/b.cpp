#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    double sum = 0;
    rep(i,n){
        double x;
        string u;
        cin >> x >> u;
        if (u == "BTC") x *= 380000.0;
        sum += x;
    }
    printf("%.20f\n", sum);
    return 0;
}

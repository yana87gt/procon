#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    double sum = 0;
    rep(i,n){
        double a;
        cin >> a;
        sum += 1.0/a;
    }
    printf("%.10f\n", 1.0/sum);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    string s;
    cin >> n >> s;
    int k = 0, max_k = 0;
    double sum = 0;
    rep(i,n){
        if (s[i] == '-') {
            k = 0;
            sum += 1.0;
        } else {
            sum += 1.0/(k+2.0);
            k++;
            max_k = max(max_k, k);
        }
    }
    printf("%.10f\n",sum - 1.0 + 1.0/(max_k+2.0));
    return 0;
}

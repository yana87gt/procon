#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i< int(n); i++)

int main(void){
    int n;
    cin>>n;
    rep(i,n){
        double a;
        cin>>a;
        printf("%.10f\n", sqrt(a)*sqrt(2)/2.0);
    }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m;
    cin>>n>>m;
    int t = 100*(n-m)+1900*m;
    double p = pow(0.5,m);
    double q = 1-pow(0.5,m);
    double res = 0;
    rep(i,10000){
        res += t*(i+1)*p;
        p *= q;
    }
    cout<<round(res)<<endl;
    return 0;
}

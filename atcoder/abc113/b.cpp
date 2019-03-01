#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

double T,A;
double f(double x){
    return abs(T-0.006*x - A);
}

int main(void){
    int n;
    cin>>n>>T>>A;
    vector<double> h(n);
    rep(i,n)cin>>h[i];
    int index = 0;
    rep(i,n){
        if(f(h[i]) < f(h[index])) {
            index = i;
        }
    }
    cout<< index + 1 << endl;
    return 0;
}

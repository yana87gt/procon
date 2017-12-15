#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N;
    cin>>N;
    vector<int> t(N);
    vector<double> v(N);
    int T=0;
    rep(i,N) {
        cin>>t[i];
        T += t[i]*2;
    }
    rep(i,N) cin>>v[i];
    vector<double> s(T+1);
    rep(x,T){
        if(x<=T/2) s[x] = x/2.0;
        else s[x] = (T-x)/2.0;
    }
    int l=0,r=0;
    rep(i,N){
        r += 2*t[i];
        rep(x,T){
            if(x<=l) s[x] = min(s[x],v[i]+(l-x)/2.0);
            else if(x<=r) s[x] = min(s[x],v[i]);
            else s[x] = min(s[x],v[i]+(x-r)/2.0);
        }
        l = r;
    }

    double sum = 0;
    rep(x,T){
        sum += 0.25*(s[x]+s[x+1]);
    }
    printf("%.2f\n",sum);

    return 0;
}

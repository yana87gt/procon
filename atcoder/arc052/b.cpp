#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    int N,Q,X,R,H,A,B;
    cin>>N>>Q;
    double c[20002]={};
    while(N--){
        cin>>X>>R>>H;
        double v=R*R*M_PI/3.0/H/H;
        rep1(i,H) c[X+H-i+1] += (3*i*i-3*i+1)*v;
    }

    rep(i,20001)c[i+1]+=c[i];

    while(Q--){
        cin>>A>>B;
        printf("%.20f\n",c[B]-c[A]);
    }

    return 0;
}

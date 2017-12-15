#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bitset<10> f[100];
int p[100][11];

int main(void){
    int n;
    cin>>n;
    rep(i,n)rep(j,10) {
        bool bit;
        cin>>bit;
        f[i][j] = bit;
    }
    rep(i,n)rep(j,11) cin>>p[i][j];

    int res = -(1e9);
    rep(mask,1<<10)if(mask){
        int sum = 0;
        rep(i,n) sum += p[i][(bitset<10>(mask) & f[i]).count()];
        res = max(res,sum);
    }
    cout<<res<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 1e9;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    int pre = -INF;
    int z = n;
    rep(i,n){
        cin>>x[i];
        if(pre < 0 && x[i] >= 0) z = i;
        pre = x[i];
    }
    int res = INF;
    rep(i,k+1){
        int l = z+i-k, r = z+i-1;
        if(l<0 || n<=r) continue;
        int lv = max(-x[l],0), rv = max(x[r],0);
        res = min({res, lv*2+rv, lv+rv*2});
    }
    cout<<res<<endl;
    return 0;
}

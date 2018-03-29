#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()

int main(void){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];

    int res = 0;
    rep(k,29){
        vector<int> bk(n);
        rep(i,n){
            bk[i] = b[i] % (1<<(k+1));
        }
        sort(all(bk));
        int bit = 0;
        rep(i,n){
            int pos[4];
            int ak = a[i] % (1<<(k+1));
            rep(m,4){
                pos[m] = lb(bk,((m+1)<<k) - ak);
            }
            bit ^= (pos[3]-pos[2] + pos[1]-pos[0]) & 1;
        }
        res |= bit<<k;
    }
    cout<<res<<endl;
    return 0;
}

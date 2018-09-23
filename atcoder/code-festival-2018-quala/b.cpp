#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int> v(n,b);
    rep(i,m){
        int l,r;
        cin>>l>>r;
        l--,r--;
        for(int k = l; k<=r; k++){
            v[k] = a;
        }
    }
    cout<<accumulate(all(v),0)<<endl;
    return 0;
}

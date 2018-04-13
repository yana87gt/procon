#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n,k;
    cin>>n>>k;
    ll res = k;
    rep(i,n-1){
        res *= k-1;
    }
    cout<<res<<endl;
    return 0;
}

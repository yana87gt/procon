#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    int res = 0;
    rep(i,n){
        cin>>a[i];
        while(a[i]%2 ==0){
            a[i] /= 2;
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}

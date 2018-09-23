#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

using ll = long long;

bool solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    rep(i,n-2){
        if(a[i]+a[i+1] > a[i+2]) return true;
    }
    return false;
}

int main(void){
    cout<<((solve()) ? "possible" : "impossible")<<endl;
    return 0;
}

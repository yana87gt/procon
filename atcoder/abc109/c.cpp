#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()


ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}

int main(void){
    int n;
    cin>>n;
    vector<ll> x(n+1);
    rep(i,n+1) cin>>x[i];
    sort(all(x));
    ll G = x[1]-x[0];
    rep(i,n){
        G = gcd(G, x[i+1]-x[i]);
    }
    cout << G << endl;
    return 0;
}

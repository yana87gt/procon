#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

int digits(ll n){
    int i=1;
    while(n/=10)i++;
    return i;
}

int main(void){
    ll n;
    cin>>n;
    int res = 11;
    for(ll a = 1; a < sqrt(n)+1; a++){
        if(n%a==0){
            ll b = n/a;
            int f = max(digits(a),digits(b));
            res = min(res,f);
        }
    }
    cout<<res<<endl;
    return 0;
}

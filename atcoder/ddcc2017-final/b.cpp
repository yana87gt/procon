#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(void){
    ll N,X=1,Y,Z;
    cin>>N>>Z;
    while(N--){
        cin>>Y;
        X = lcm(X,gcd(Y,Z));
    }
    cout<<X<<endl;
}

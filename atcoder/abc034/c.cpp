#include <iostream>
using namespace std;
typedef long long ll;
ll M = 1e9+7;

ll fact(int n)
{
    ll ans=1;
    for(int i=1;i<=n;++i)
    {
        ans*=i;
        if(ans>=M)ans%=M;
    }
    return ans;
}

ll mul(ll a,ll b){ return (a*b)%M;}

ll power(ll n, ll r)
{
    if(r==1)return n;
    if(r%2==0)return power(mul(n,n),r/2);
    else return mul(power(mul(n,n),r/2),n);
}

int main(void)
{
    int W,H;
    cin >> W >> H;
    --W; --H;
    cout << mul(fact(H+W),power(mul(fact(H),fact(W)),M-2)) << endl;
    return 0;
}

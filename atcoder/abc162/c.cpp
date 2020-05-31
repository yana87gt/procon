#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}


int main(void){
    int k;
    cin >> k;
    ll sum = 0;
    rep1(a,k)rep1(b,k)rep1(c,k){
        sum += gcd(a,gcd(b,c));
    }
    cout << sum << endl;
    return 0;
}

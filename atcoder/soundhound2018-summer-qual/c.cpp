#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n,m,d;
    cin>>n>>m>>d;
    printf("%.10f\n",(m-1)*(n-d)*(d ? 2.0 : 1.0)/n/n);
    return 0;
}

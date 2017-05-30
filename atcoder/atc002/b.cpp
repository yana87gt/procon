#include <iostream>
using namespace std;
typedef long long ll;
ll N,M,P;
ll power(ll n, ll r){
    if(r==0)return 1;
    return power(n*n%M,r>>1)*(r&1 ? n : 1)%M;
}
int main(void){
    cin>>N>>M>>P;
    cout<<power(N,P)<<endl;
}

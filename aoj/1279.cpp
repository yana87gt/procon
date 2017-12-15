#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

#define N 1300000
bool prime[N];

int solve(int n){
    if(prime[n]) return 0;
    int l=n,r=n;
    while(!prime[l])l--;
    while(!prime[r])r++;
    return r-l;
}

int main(void){
    rep(i,N) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2; i<=sqrt(N); i++){
        if(!prime[i]) continue;
        for(int j=i*i; j<N; j+=i){
            prime[j] = false;
        }
    }

    int n;
    while(cin>>n,n){
        cout<<solve(n)<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

#define SIZE 1000010
vector<bool> prime(SIZE,true);
void init(){
    prime[0] = prime[1] = false;
    rep(i,SIZE){
        if(!prime[i])continue;
        for(int j=i*2;j<SIZE;j+=i){
            prime[j] = false;
        }
    }
}

int main(void){
    vector<bool> f(SIZE);
    init();
    rep(i,SIZE){
        if(prime[i] && prime[(i+1)/2]){
            f[i] = true;
        }
    }
    vector<int> imos(SIZE);
    rep(i,SIZE-1){
        imos[i] += f[i];
        imos[i+1] = imos[i];
    }
    int q;
    cin>>q;
    rep(_,q){
        int l,r;
        cin>>l>>r;
        cout<<imos[r]-imos[l-1]<<endl;
    }
    return 0;
}

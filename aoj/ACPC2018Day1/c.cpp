#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)


#define SIZE 20000000
vector<bool> prime(SIZE,true);
vector<int> ps;

void init(){
    prime[0] = prime[1] = false;
    rep(i,SIZE){
        if(!prime[i]) continue;
        for(int j = i*2; j<SIZE; j+=i){
            prime[j] = false;
        }
    }
}

int main(){
    init();
    int n;
    cin>>n;
    int cnt = 0;
    rep1(i,n){
        if(prime[i] && prime[i+2]){
            cnt += 2;
        }
    }
    cout<<cnt<<endl;
}
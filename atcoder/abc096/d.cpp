#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool prime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(void){
    int N;
    cin>>N;
    vector<int> res;
    rep(i,11111){
        int p = i*5+4;
        if(prime(p)){
            res.push_back(p);
        }
        if(res.size() == N) break;
    }
    rep(i,N){
        cout<<res[i]<<(i==N-1 ? "\n" : " ");
    }
    return 0;
}

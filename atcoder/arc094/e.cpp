#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

typedef long long ll;

int main(void){
    int n;
    cin>>n;
    ll sum = 0, rem = INF;
    bool all_same = true;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        sum += a;
        if(a!=b) all_same = false;
        if(a>b) rem = min(rem,b);
    }
    if(all_same){
        cout<<0<<endl;
    }else{
        cout<<sum-rem<<endl;
    }
    return 0;
}

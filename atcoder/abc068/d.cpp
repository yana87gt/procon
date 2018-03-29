#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef long long ll;

int main(void){
    ll k;
    cin>>k;
    cout<<50<<endl;
    ll a = k/50;
    rep(i,50){
        if(a==k/50+50-k%50){
            a++;
        }
        cout<<a<<" ";
        a++;
    }
    cout<<endl;
    return 0;
}
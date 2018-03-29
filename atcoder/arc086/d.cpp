#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int a[50];

int main(void){
    int n,mn=INF,mn_idx,mx=-INF,mx_idx;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        if(mn>a[i]){
            mn = a[i];
            mn_idx = i;
        }
        if(mx<a[i]){
            mx = a[i];
            mx_idx = i;
        }
    }
    cout<<2*n-1<<endl;
    if(abs(mn)<abs(mx)){
        rep(i,n){
            cout<<mx_idx+1<<" "<<i+1<<endl;
        }
        rep(i,n-1){
            cout<<i+1<<" "<<i+2<<endl;
        }
    }else{
        rep(i,n){
            cout<<mn_idx+1<<" "<<i+1<<endl;
        }
        rep(i,n-1){
            cout<<n-i<<" "<<n-i-1<<endl;
        }
    }

}

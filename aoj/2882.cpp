#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)

bool uruu(int n, vector<int> &a, int x){
    rep(i,n){
        if(x % a[i] == 0) return (i%2 == 0);
    }
    return (n%2 == 0);
}

int main(void){
    int n,l,r;
    while(cin>>n>>l>>r, n|l|r){
        vector<int> a(n);
        rep(i,n) cin>>a[i];
        int cnt = 0;
        for(int x = l; x<=r; x++){
            if(uruu(n,a,x)) cnt++;
        }
        cout<<cnt<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
int main(void){
    int n,l,r;
    cin>>n>>l>>r;
    rep(i,n){
        int a,res;
        cin>>a;
        if(a<=l)res = l;
        else if(r<=a)res = r;
        else res = a;
        cout<<res<<(i < n-1 ? " ":"\n");
    }
    return 0;
}

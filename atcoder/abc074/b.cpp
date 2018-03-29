#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,k,x;
    cin>>n>>k;
    int sum = 0;
    rep(i,n){
        cin>>x;
        sum += 2*min(x,k-x);
    }
    cout<<sum<<endl;
    return 0;
}

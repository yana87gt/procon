#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,d,a,x=0;
    cin>>n>>d>>x;
    rep(i,n){
        cin>>a;
        x += (d-1)/a + 1;
    }
    cout<<x<<endl;
    return 0;
}

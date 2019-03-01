#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,x;
    cin>>n>>x;
    int sum = 0;
    int mx = 0;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        mx = max(mx, b);
        sum += a*b;
    }
    cout << sum + x*mx <<endl;

    return 0;
}

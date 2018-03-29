#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int dsum(int x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    int sum = 0;
    rep(i,n+1){
        int ds = dsum(i);
        if(ds >= a && ds <= b){
            sum += i;
        }
    }
    cout<<sum<<endl;
    return 0;
}

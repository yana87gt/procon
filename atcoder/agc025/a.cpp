#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define INF 1e9

int digit_sum(int x){
    int res = 0;
    while(x>0){
        res += x%10;
        x /= 10;
    }
    return res;
}

int main(void){
    int n;
    cin>>n;
    int res = INF;
    rep1(a,n-1){
        res = min(res,digit_sum(a)+digit_sum(n-a));
    }
    cout<<res<<endl;
    return 0;
}

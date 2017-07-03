#include <bits/stdc++.h>
using namespace std;
int main(void){
    int K,T,a,ma;
    cin>>K>>T;
    while(T--){
        cin>>a;
        ma=max(ma,a);
    }
    cout<<max(2*ma-K-1,0)<<endl;
    return 0;
}

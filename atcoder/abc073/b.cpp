#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,sum=0;
    cin>>N;
    rep(i,N){
        int l,r;
        cin>>l>>r;
        sum += r-l+1;
    }
    cout<<sum<<endl;
    return 0;
}

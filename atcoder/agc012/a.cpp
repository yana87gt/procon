#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
    int N,a[300000];
    cin>>N;
    rep(i,N*3)cin>>a[i];
    sort(a,a+N*3);
    ll sum=0;
    for(int i=N;i<N*3;i+=2) sum+=a[i];
    cout<<sum<<endl;
    return 0;
}

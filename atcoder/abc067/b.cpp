#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int N,K;
    cin>>N>>K;
    vector<int> l(N);
    rep(i,N)cin>>l[i];
    sort(all(l));
    int sum=0;
    rep(i,K){
        sum+=l[N-i-1];
    }
    cout<<sum<<endl;

    return 0;
}

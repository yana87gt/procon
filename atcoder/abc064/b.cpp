#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N;
    cin>>N;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    sort(a.begin(),a.end());
    cout<<a[N-1]-a[0]<<endl;
    return 0;
}

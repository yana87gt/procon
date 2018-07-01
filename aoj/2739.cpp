#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);++i)
using namespace std;

int main(void){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int sum = a[0]-m + max(t-a[n-1]-m,0);
    rep(i,n-1){
        sum += max(a[i+1]-a[i]-m*2, 0);
    }
    cout<<sum<<endl;
    return 0;
}

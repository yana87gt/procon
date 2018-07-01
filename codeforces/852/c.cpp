#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> b(n);
    using P = pair<int,int>; // <sum,i>
    vector<P> p(n);
    rep(i,n){
        p[i] = {a[i]+a[(i+1)%n], i};
    }
    sort(all(p));
    rep(i,n){
        b[p[i].second] = i;
    }
    rep(i,n){
        cout<<b[i]<<(i==n-1 ? "\n": " ");
    }
    return 0;
}

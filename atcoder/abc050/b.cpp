#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    cin>>n;
    vector<int> t(n);
    rep(i,n) cin>>t[i];
    int sum = accumulate(all(t),0);
    int m;
    cin>>m;
    rep(i,m){
        int p,x;
        cin>>p>>x;
        cout<<sum-t[p-1]+x<<endl;
    }
    return 0;
}

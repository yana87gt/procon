#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> imos(m+1);
    int sum = 0;
    rep(i,n){
        int l,r,s;
        cin>>l>>r>>s;
        l--,r--;
        imos[l] += s;
        imos[r+1] -= s;
        sum += s;
    }
    rep(i,m){
        imos[i+1] += imos[i];
    }
    imos.pop_back();
    cout<<sum-(*min_element(all(imos)))<<endl;
    return 0;
}

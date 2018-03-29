#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    map<char,int> mp;
    rep(i,n){
        string s;
        cin>>s;
        mp[s[0]]++;
    }
    string MARCH = "MARCH";
    ll a[5]={};
    rep(i,5){
        a[i] = mp[MARCH[i]];
    }
    ll res = 0;
    rep(i,5)rep(j,i)rep(k,j){
        res += a[i]*a[j]*a[k];
    }
    cout<<res<<endl;
    return 0;
}

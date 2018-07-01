#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    ll v[3];
    ll k;
    cin>>v[0]>>v[1]>>v[2]>>k;
    sort(v,v+3);
    cout<<v[0]+v[1]+(v[2]<<k)<<endl;
    return 0;
}

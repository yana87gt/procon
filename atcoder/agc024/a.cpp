#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF ll(1e18)

int main(void){
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll res;
    if(k&1){
        res = b-a;
    }else{
        res = a-b;
    }
    if(abs(res)>INF){
        cout<<"Unfair"<<endl;
    }else{
        cout<<res<<endl;
    }
    return 0;
}

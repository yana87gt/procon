#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x,y;
    cin>>x>>y;
    if(x%y==0)cout<<-1<<endl;
    else {
        ll res = x;
        while(res%y==0) res += x;
        cout<<res<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x,y;
    cin>>x>>y;
    int cnt=0;
    while(x<=y){
        cnt++;
        x *= 2;
    }
    cout<<cnt<<endl;
    return 0;
}

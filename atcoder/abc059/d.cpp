#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll x,y;
    cin >> x >> y;
    cout<<((abs(x-y)>1) ? "Alice" : "Brown")<<endl;
    return 0;
}

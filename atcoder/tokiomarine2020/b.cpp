#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;
    cout << ((abs(a-b) <= t*(v-w)) ? "YES" : "NO") << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x == 0) return 0;
    int n = to_string(x).size();
    int h = to_string(x)[0]-'0';
    int mod = pow(10,n-1);
    return h * f(mod-1) + (h>1 ? mod : x%mod+1) + f(x%mod);
}

int main(void){
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}

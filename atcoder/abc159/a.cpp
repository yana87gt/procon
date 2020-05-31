#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nC2(ll n){
    return n*(n-1)/2;
}

int main(void){
    int n, m;
    cin >> n >> m;
    cout << (nC2(n) + nC2(m)) << endl;
    return 0;
}

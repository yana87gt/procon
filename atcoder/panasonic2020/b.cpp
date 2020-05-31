#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll h,w;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
    } else {
        cout << (h*w+1)/2 << endl;
    }
    return 0;
}

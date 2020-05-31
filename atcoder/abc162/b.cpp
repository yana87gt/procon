#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    ll sum = 0;
    rep1(i,n) {
        if (i % 5 != 0 && i % 3 != 0) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}

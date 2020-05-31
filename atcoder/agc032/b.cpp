#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    int s = n&1 ? n : n+1;
    cout << n*(n-1)/2 - n/2 << endl;
    rep1(i,n)rep1(j,i-1){
        if (i+j != s) {
            cout << i << " " << j << endl;
        }
    }
    return 0;
}

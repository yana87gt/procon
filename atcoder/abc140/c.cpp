#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
const int INF = 1e9;

int main(void){
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n-1){
        cin >> b[i];
    }
    b[n-1] = INF;
    int sum = b[0];
    rep1(i,n-1){
        sum += min(b[i-1],b[i]);
    }
    cout << sum << endl;
    return 0;
}

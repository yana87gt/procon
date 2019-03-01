#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<int> h(n+1);
    rep1(i,n) cin >> h[i];
    int sum = 0;
    rep(i,n) sum += max(h[i+1]-h[i],0);
    cout << sum << endl;
    return 0;
}

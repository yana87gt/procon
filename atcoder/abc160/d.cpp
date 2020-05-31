#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n, x, y;
    cin >> n >> x >> y;
    x--,y--;
    map<int,int> cnt;
    rep(r,n)rep(l,r){
        cnt[min(abs(x-l)+1+abs(y-r), r-l)]++;
    }
    rep1(i,n-1){
        cout << cnt[i] << endl;
    }
    return 0;
}

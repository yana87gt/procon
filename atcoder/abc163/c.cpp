#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    map<int,int> cnt;
    rep(i,n-1){
        int a;
        cin >> a;
        cnt[a]++;
    }
    rep1(i,n){
        cout << cnt[i] << endl;
    }
    return 0;
}

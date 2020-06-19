#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    rep(i,n) {
        cin >> a[i];
    }
    rep(t,k){
        vector<int> nxt(n+1, 0);
        rep(i,n){
            int l = max(i-a[i], 0);
            int r = min(i+a[i]+1,n);
            nxt[l]++;
            nxt[r]--;
        }
        rep1(i,n){
            nxt[i] += nxt[i-1];
        }
        nxt[n] = 0;
        a = move(nxt);
        if (count(all(a), n) == n) {
            break;
        }
    }
    rep(i,n){
        cout << a[i] << (i<n-1 ? " " : "\n");
    }
    return 0;
}

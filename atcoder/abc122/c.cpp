#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cnt(n+1);
    rep(i,n-1){
        cnt[i+1] += cnt[i];
        if (s[i] == 'A' && s[i+1] == 'C') {
            cnt[i+2]++;
        }
    }
    cnt[n] += cnt[n-1];
    rep(i,q){
        int l,r;
        cin >> l >> r;
        // [l,r)
        cout << cnt[r] - cnt[l] << endl;
    }
    return 0;
}

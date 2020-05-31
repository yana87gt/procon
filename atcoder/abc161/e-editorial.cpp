#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> L = {-n}, R = {n*2};
    rep(i,n){
        if (s[i] == 'o' && L.back() + c < i) {
            L.push_back(i);
        }
    }
    rep(ii,n){
        int i = n-1-ii;
        if (s[i] == 'o' && i < R.back() - c) {
            R.push_back(i);
        }
    }
    rep1(i,k){
        if (L[i] == R[k-i+1]) {
            cout << L[i]+1 << endl;
        }
    }
    return 0;
}

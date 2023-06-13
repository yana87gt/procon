#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    {
        vector<int> cntA(n+1), cntB(n+1);
        rep(i,n) cntA[a[i]]++;
        rep(i,n) cntB[b[i]]++;
        rep1(i,n) if(cntA[i]+cntB[i] > n) {
            cout << "No" << endl;
            return 0;
        }
    }
    {
        cout << "Yes" << endl;
        vector<int> ar(n+1, -1), bl(n+1, n+1);
        rep(i,n) {
            chmax(ar[a[i]],i);
            chmin(bl[b[i]],i);
        }
        int k = 0;
        rep1(i,n) {
            chmax(k, ar[i] - bl[i] + 1);
        }
        rep(i,n) {
            cout << b[(i+n-k)%n] << (i<n-1 ? " " : "\n");
        }
    }

    return 0;
}

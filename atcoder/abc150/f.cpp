#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;


class rolling_hash {
    int n;
    static const int MS = 2;
    const vector<ll> mod = {999999937LL, 1000000007LL};
    static const ll base = 9973;
    vector<long long> hs[MS], pw[MS];
    rolling_hash(){}

    template<typename T>
    rolling_hash(T s) {
        n = s.size();
        for (int i = 0; i < MS; i++) {
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j+1] = pw[i][j]*base%mod[i];
                hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
            }
        }
    }

    long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
        return ret;
    }

    bool match(int l, int r, long long h[]) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l,r,i)==h[i];
        return ret;
    }
};

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    string sa, sb; //2倍文字列
    rep(i,n){
        ostringstream sout;
        sout << setfill('0') << setw(10) << (a[i] ^ a[(i+1)%n]);
        sa += sout.str();
        sout.str("");
        sout << setfill('0') << setw(10) << (b[i] ^ b[(i+1)%n]);
        sb += sout.str();
    }
    rolling_hash ra(sa+sa), rb(sb);
    rep(k,n){
        if (ra.hash(k*10, k*10 + n*10, 0) == rb.hash(0, n*10, 0)) {
            cout << k << " " << (a[k] ^ b[0]) << endl;
        }
    }
    return 0;
}

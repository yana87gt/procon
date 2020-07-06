#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 1e9+7;
    static vector<modint> factorial;

    modint(): num(0) {};
    modint(ll n_): num((n_ + MOD) % MOD) {}
    modint(const modint &r): num(r.num) {}
    operator ll() const { return (num+MOD)%MOD; }
    friend istream& operator>>(istream& is, modint &r){
        ll num_;
        is >> num_;
        r = num_;
        return is;
    }
    modint operator+(const modint &r) const { return modint(num + r.num); }
    modint operator-(const modint &r) const { return modint(num - r.num); }
    modint operator*(const modint &r) const { return modint(num * r.num); }

    template<typename T>
    modint operator^(const T &r) const {
        if(r == 0) return 1;
        return (((*this)*(*this)) ^ (r/2)) * modint(r&1 ? num : 1);
    }
    modint operator/(const modint &r) const { return num * (r^(MOD-2)); }

    modint operator+=(const modint &r) { return *this = *this + r; }
    modint operator-=(const modint &r) { return *this = *this - r; }
    modint operator*=(const modint &r) { return *this = *this * r; }
    modint operator/=(const modint &r) { return *this = *this / r; }

    template<typename T>
    modint operator^=(const T &r) { return *this = *this ^ r; }

    static modint pow(const modint x, ll r) {
        return x^r;
    }

    static modint fact(int n){
        if((int)factorial.size() <= n) {
            int size = factorial.size();
            factorial.resize(n+1);
            for (int i = size; i <= n; i++) {
                factorial[i] = factorial[i-1] * modint(i);
            }
        }
        return factorial[n];
    }

    static modint C(ll n,ll r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }
};
vector<modint> modint::factorial = {1};
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define H(a,b) C(a+b, a)


int main(void) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> pos, neg;
    rep(i,n) {
        if (a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    ll P = pos.size(), N = neg.size();
    vector<ll> cand;
    if (k == n) {
        cand = a;
    } else if ((P == 0) && (k % 2 == 1)) {
        // 0以下にせざるを得ない
        sort(all(neg),greater<ll>());
        cand = vector<ll> (neg.begin(), neg.begin()+k);
    } else {
        // 絶対値大きい順にsort
        sort(all(pos),greater<ll>());
        sort(all(neg));
        int cntP = 0, cntN = 0;
        if (k % 2 == 1) {
            cand.push_back(pos[cntP++]);
            k--;
        }
        rep(i,k/2){
            if (cntP + 1 >= P) {
                cand.push_back(neg[cntN++]);
                cand.push_back(neg[cntN++]);
            } else if (cntN +1 >= N) {
                cand.push_back(pos[cntP++]);
                cand.push_back(pos[cntP++]);
            } else if (pos[cntP]*pos[cntP+1] >= neg[cntN]*neg[cntN+1]) {
                cand.push_back(pos[cntP++]);
                cand.push_back(pos[cntP++]);
            } else  {
                cand.push_back(neg[cntN++]);
                cand.push_back(neg[cntN++]);
            }
        }
    }
    modint res = 1;
    for (ll c : cand) {
        res *= modint(c);
    }
    cout << res << endl;
    return 0;
}

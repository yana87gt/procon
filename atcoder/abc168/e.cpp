#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

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
                factorial[i] = fact(i-1) * modint(i);
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


ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}


int main(void){
    ll n;
    cin >> n;
    ll origin = 0;
    map<pair<ll, ll>, ll> cnt1, cnt2;
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            origin ++;
        } else if (a == 0 && b != 0) {
            cnt2[{0, 1}]++;
        } else if (a != 0 && b == 0) {
            cnt1[{1, 0}]++;
        } else {
            ll g = gcd(abs(a),abs(b));
            a /= g;
            b /= g;
            if (b < 0) {
                a = -a;
                b = -b;
            }
            if (a > 0) {
                cnt1[{a,b}]++;
            } else {
                cnt2[{a,b}]++;
            }
        }
    }
    modint res = 1;
    for (auto itr1 : cnt1) {
        auto p = itr1.first;
        ll a = p.first;
        ll b = p.second;
        if (cnt2.count({-b,a})) {
            res *= (modint::pow(2,cnt1[{a,b}]) + modint::pow(2,cnt2[{-b,a}]) - modint(1));
            cnt2.erase({-b,a});
        } else {
            res *= (modint::pow(2,cnt1[{a,b}]));
        }
    }
    for (auto itr2 : cnt2) {
        res *= (modint::pow(2,itr2.second));
    }
    cout << res - modint(1) + modint(origin) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 998244353;
    static vector<modint> factorial;

    modint(): num(0) {};
    modint(ll num_): num((num_ + MOD) % MOD) { assert(num >= 0); }
    modint(const modint &r): num(r.num) {}
    operator ll() const { return num; }

    template <typename T>
    static void is_valid(const T &num_) {
        assert(num_ >= 0 && num_ < MOD);
        static_assert(is_integral<T>() || is_same<T,modint>(), "T is not integral.");
    }

    template <typename T>
    modint operator+(const T &r) const { is_valid(r); return num + r; }
    template <typename T>
    modint operator-(const T &r) const { is_valid(r); return num - r; }
    template <typename T>
    modint operator*(const T &r) const { is_valid(r); return num * r; }
    template <typename T>
    modint operator/(const T &r) const { is_valid(r); return num * pow(r, MOD-2); }

    template <typename T>
    modint operator+=(const T &r) { return *this = *this + r; }
    template <typename T>
    modint operator-=(const T &r) { return *this = *this - r; }
    template <typename T>
    modint operator*=(const T &r) { return *this = *this * r; }
    template <typename T>
    modint operator/=(const T &r) { return *this = *this / r; }

    static modint pow(const modint &x, const ll &r) {
        if(r == 0) return 1;
        return pow(x*x, r/2) * modint(r&1 ? x : modint(1));
    }

    static modint fact(int n){
        if((int)factorial.size() <= n) {
            int size = factorial.size();
            factorial.resize(n+1);
            for (int k = size; k <= n; k++) {
                factorial[k] = factorial[k-1] * k;
            }
        }
        return factorial[n];
    }

    static modint C(int n, int r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }

    friend istream& operator>>(istream& is, modint &r){
        ll num_;
        is >> num_;
        r = num_;
        return is;
    }
};
template <typename T>
modint operator+(const T &l, const modint &r) { modint::is_valid(l); return l + r; }
template <typename T>
modint operator-(const T &l, const modint &r) { modint::is_valid(l); return l - r; }
template <typename T>
modint operator*(const T &l, const modint &r) { modint::is_valid(l); return l * r; }
template <typename T>
modint operator/(const T &l, const modint &r) { modint::is_valid(l); return l * modint::pow(r, modint::MOD-2); }
vector<modint> modint::factorial = {1};
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define H(a,b) C(a+b, a)


int main(void){
    int n;
    cin >> n;
    modint sum = 0;
    for (int i = n/2+1; i <= n; i++) {
        sum += C(n,i) * modint::pow(2,n-i) * 2;
    }
    cout << modint::pow(3,n) - sum << endl;
    return 0;
}

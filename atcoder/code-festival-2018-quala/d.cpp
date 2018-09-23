#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define ub(s,x) upper_bound(all(s),x)-s.begin()

class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 1e9+7;
    static vector<modint> factorial;

    modint(): num(0) {};
    modint(ll _n): num((_n + MOD) % MOD) {}
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

    static modint fact(int n){
        if((int)factorial.size() <= n) factorial.resize(n+1);
        if(factorial[n]) return factorial[n];
        if(n == 0) return 1;
        return factorial[n] = modint(n) * fact(n-1);
    }

    static modint com(ll n,ll r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }
};
vector<modint> modint::factorial;

int main(void){
    int D,F,T,n;
    cin>>D>>F>>T>>n;
    vector<int> x(n+2);
    vector<modint> dp(n+2);
    rep1(i,n) cin>>x[i];
    x[n+1] = 2e9;
    dp[0] = 1;
    dp[1] = -1;
    modint res = 0;
    rep(i,n+1){
        int pos = x[i];
        int t = ub(x, pos+F-T);
        int f = ub(x, pos+F);
        int k = max(t-i-1,0);
        dp[i+1] += dp[i];
        modint add_value = dp[i]*(modint(2)^k);
        dp[t] += add_value;
        dp[f] -= add_value;
        if(D <= pos+F){
            res += add_value;
        }
    }
    cout<<res<<endl;
    return 0;
}

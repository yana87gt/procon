#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


int main(void){
    ll n;
    cin >> n;
    auto primes = factorize(n);
    int res = 0;
    for (auto itr : primes) {
        int r = itr.second;
        int e = 1;
        while (e <= r) {
            res++;
            r -= e;
            e++;
        }
    }
    cout << res << endl;
    return 0;
}

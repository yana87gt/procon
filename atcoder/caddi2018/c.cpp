#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)

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
    ll n, p;
    cin >> n >> p;
    auto cnt = factorize(p);
    ll res = 1;
    for (auto itr : cnt) {
        res *= pow(itr.first, itr.second / n);
    }
    cout << res << endl;
    return 0;
}

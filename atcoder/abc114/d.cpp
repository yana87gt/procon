#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define lb(s,x) (lower_bound(all(s),x)-s.begin())
typedef long long ll;

int n;
vector<int> cnt;

void count_primes() {
    vector<int> rem(n+1);
    cnt.resize(n+1);
    rep1(i,n) rem[i] = i;
    rep1(i,n){
        if(rem[i] == 1) continue;
        for(int j = i; j <= n; j += i){
            while(rem[j] % i == 0){
                rem[j] /= i;
                cnt[i]++;
            }
        }
    }
}

int num(int x){
    return n - lb(cnt,x) + 1;
}

ll calc(vector<int> v){
    sort(all(v), greater<int>());
    ll res = 1;
    rep(i, v.size()){
        res *= max(num(v[i]-1)-i, 0);
    }
    return res;
}


int main(void){
    cin >> n;
    count_primes();
    sort(all(cnt));
    cout << calc({3,5,5})/2 + calc({3,25}) + calc({5,15}) + calc({75}) << endl;
    return 0;
}

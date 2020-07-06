#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a), greater<ll>());
    using P = pair<ll, ll>;
    priority_queue<P> que;
    que.push({a[0], a[0]});
    ll score = 0;
    rep1(i,n-1){
        P t = que.top(); que.pop();
        score += t.first;
        que.push({a[i], t.first});
        que.push({a[i], t.second});
    }
    cout << score << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    ll n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    rep1(i,n) cin >> a[i];
    int cur = 1;
    vector<ll> step(n+1);
    vector<bool> visited(n+1);
    ll cycle = 0;
    while (k > 0) {
        visited[cur] = true;
        int to = a[cur];
        if (visited[to]) {
            k--;
            cycle = step[cur] - step[to] + 1;
            k %= cycle;
            cur = to;
            break;
        }
        step[to] = step[cur] + 1;
        cur = to;
        k--;
    }
    while (k > 0) {
        cur = a[cur];
        k--;
    }
    cout << cur << endl;

    return 0;
}

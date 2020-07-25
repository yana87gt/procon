#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
#define bit(k) (1LL<<(k))
#define INF ll(1e18)

struct Point
{
    ll x,y,p;
    bool operator<(const Point &rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
};

vector<int> get_state(int id, int n) {
    vector<int> state(n);
    rep(i,n){
        state[i] = id % 3;
        id /= 3;
    }
    return state;
}

int main(void) {
    int n;
    cin >> n;
    vector<Point> v(n);
    rep(i,n) cin >> v[i].x >> v[i].y >> v[i].p;
    vector<vector<ll>> distX(1<<n, vector<ll>(n, INF)), distY(1<<n, vector<ll>(n, INF));
    rep(i,n){
        distX[0][i] = abs(v[i].x);
        distY[0][i] = abs(v[i].y);
    }
    rep(mask, 1<<n) {
        rep(road,n) {
            if (mask & bit(road)) continue;
            rep(i,n) {
                distX[mask|bit(road)][i] = min(distX[mask][i], abs(v[road].x - v[i].x));
                distY[mask|bit(road)][i] = min(distY[mask][i], abs(v[road].y - v[i].y));
            }
        }
    }
    vector<ll> res(n+1, INF);
    rep(id, pow(3,n)+0.5) {
        vector<int> state = get_state(id,n);
        int maskX = 0, maskY = 0;
        rep(i,n) {
            if (state[i] == 1) maskX |= bit(i);
            if (state[i] == 2) maskY |= bit(i);
        }
        int use = 0;
        ll sum = 0;
        rep(i,n) {
            if (state[i]) use++;
            sum += min(distX[maskX][i], distY[maskY][i]) * v[i].p;
        }
        res[use] = min(res[use], sum);
    }
    rep(i,n+1){
        cout << res[i] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;


// ei13333 うしさんライブラリ
// 座標圧縮 #座圧
template< typename T >
struct Compress {
    vector< T > xs;

    Compress() = default;

    Compress(const vector< T > &vs) {
        add(vs);
    }

    Compress(const initializer_list< vector< T > > &vs) {
        for(auto &p : vs) add(p);
    }

    void add(const vector< T > &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) {
        xs.emplace_back(x);
    }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector< int > get(const vector< T > &vs) const {
        vector< int > ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const {
        return xs[k];
    }

    int size() const {
        return xs.size();
    }
};

int main(void){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(n), d(m), e(m), f(m);
    // a,b,d -> x
    // c,e,f -> y
    Compress<ll> comX, comY;
    comX.add(0);
    comY.add(0);
    rep(i,n) {
        cin >> a[i] >> b[i] >> c[i];
        comX.add(a[i]);
        comX.add(b[i]);
        comY.add(c[i]);
    }
    rep(i,m) {
        cin >> d[i] >> e[i] >> f[i];
        comX.add(d[i]);
        comY.add(e[i]);
        comY.add(f[i]);
    }
    comX.build();
    comY.build();
    int Y = comY.size()*2;
    int X = comX.size()*2;
    vector<vector<bool>> wall(Y, vector<bool>(X));
    rep(i,n){
        int x1 = comX.get(a[i])*2;
        int x2 = comX.get(b[i])*2;
        int y = comY.get(c[i])*2;
        for (int x = x1; x <= x2; x++) {
            wall[y][x] = true;
        }
    }
    rep(i,m){
        int x = comX.get(d[i])*2;
        int y1 = comY.get(e[i])*2;
        int y2 = comY.get(f[i])*2;
        for (int y = y1; y <= y2; y++) {
            wall[y][x] = true;
        }
    }
    using P = pair<int,int>;
    queue<P> qu;
    qu.push({comY.get(0)*2, comX.get(0)*2});
    int dx[] = {-1,0,+1,0};
    int dy[] = {0,-1,0,+1};
    ll area = 0;
    while(qu.size()) {
        P front = qu.front(); qu.pop();
        int y = front.first;
        int x = front.second;
        if ((y & 1) && (x & 1)) {
            area += (comY[y/2+1] - comY[y/2]) * (comX[x/2+1] - comX[x/2]);
        }
        rep(i,4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= Y || nx >= X) {
                cout << "INF" << endl;
                return 0;
            }
            if (wall[ny][nx]) continue;
            wall[ny][nx] = true;
            qu.push({ny,nx});
        }
    }
    cout << area << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

typedef complex<ll> Point;
#define X real()
#define Y imag()

string query(Point p){
    cout << p.X << " " << p.Y << endl;
    string s;
    cin >> s;
    return s;
}

void solve(ll A) {
    vector<Point> starts = {{0,0},{-A,0},{+A,0},{0,-A},{0,+A}};
    Point hit;
    bool found = false;
    for (Point p : starts) {
        string res = query(p);
        if (res == "CENTER") return;
        if (res == "HIT") {
            hit = p;
            found = true;
            break;
        }
    }
    assert(found);

    bool found_center = false;
    auto binary_search = [&](Point p1, Point p2) {
        Point p3;
        while (abs(p2 - p1) > 1) {
            p3 = (p1 + p2)/2LL;
            string res = query(p3);
            if (res == "CENTER") {
                found_center = true;
                return p3;
            } else if (res == "HIT") {
                p1 = p3;
            } else if (res == "MISS") {
                p2 = p3;
            } else {
                assert(false);
            }
        }
        return p3;
    };
    Point pN = binary_search(hit, Point(hit.X, 1e9));
    if (found_center) return;
    Point pS = binary_search(hit, Point(hit.X, -1e9));
    if (found_center) return;
    Point pH = (pN + pS)/2LL;
    Point pE = binary_search(pH, Point(1e9, pH.Y));
    if (found_center) return;
    Point pW = binary_search(pH, Point(-1e9, pH.Y));
    if (found_center) return;
    Point center = (pE + pW)/2LL;
    for (int dx = -5; dx <= 5; dx++) {
        for (int dy = -5; dy <= 5; dy++) {
            if (query(Point(center.X + dx, center.Y + dy)) == "CENTER") return;
        }
    }
    assert(false);
}

int main(void){
    int T;
    ll A, B;
    cin >> T >> A >> B;
    rep(_,T){
        solve(A);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef complex<ll> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
#define X real()
#define Y imag()

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}

Line get_line(Point p, Point q){
    pair<ll,ll> a, b;
    if(q < p) swap(p,q);
    Point d = q - p;
    if(d.Y == 0) return {{0,p.Y},{1,p.Y}};
    if(d.X == 0) return {{p.X,1},{p.X,0}};
    d /= gcd(abs(d.X), abs(d.Y));
    ll k = p.X/d.X;
    p -= d*k;
    return {p, p+d};
}

bool onLine(Line line, Point p){
    Point a = line.first - p;
    Point b = line.second - p;
    return a.X*b.Y == b.X*a.Y;   
}

int main(void){
    int n,P;
    cin>>n>>P;
    VP ps(n);
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        ps[i] = {x,y};
    }

    bool possible = false;

    if(n <= 2){
        possible = true;
    }else{
        // 乱択
        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<> randN(0,n-1);
        int M = 300000;

        map<Line, int> lines;
        rep(i,M){
            int a,b;
            a = randN(mt);
            while(b = randN(mt), a == b);
            lines[get_line(ps[a], ps[b])]++;
        }

        priority_queue<pair<int,Line>, vector<pair<int,Line>>, greater<pair<int,Line>>> qu;
        for(auto itr : lines){
            Line line = itr.first;
            int cnt = itr.second;
            qu.push({cnt, line});
            if(qu.size() > 10) qu.pop();
        }

        // n個の点がそれに乗っているか調べる
        while(qu.size()){
            int cnt = 0;
            rep(i,n){
                if(onLine(qu.top().second, ps[i])){
                    cnt++;
                }
            }
            if(ceil(n*P/100.0) <= cnt){
                possible = true;
            }
            qu.pop();
        }
    }

    cout<<(possible ? "possible" : "impossible")<<endl;
    return 0;
}

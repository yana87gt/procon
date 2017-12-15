#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

typedef pair<int,int> Point;
typedef vector<Point> VP;
#define X first
#define Y second

bool compy(const Point &a, const Point &b) {
    return a.Y < b.Y;
}

Point p[50],pp[50];

int main(void){
    int N,K;
    scanf("%d %d",&N,&K);
    rep(i,N){
        scanf("%d %d",&p[i].X,&p[i].Y);
    }
    sort(p,p+N);
    ll res = LLONG_MAX;
    rep(r,N)rep(l,r){
        ll w = p[r].X-p[l].X;
        if(r-l+1<K)continue;
        int idx=0;
        for(int i=l;i<=r;i++){
            pp[idx++]=p[i];
        }
        int n = idx;
        sort(pp,pp+n,compy);
        rep(i,n-K+1){
            ll h = pp[i+K-1].Y-pp[i].Y;
            res = min(res,w*h);
        }
    }
    printf("%lld\n",res );
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll dist(pair<int,int> p, pair<int,int> q){
    return abs(p.first-q.first)+abs(p.second-q.second);
}

int main(void){
    int h,w,d,q;
    cin>>h>>w>>d;
    int n = h*w+1;
    vector<pair<int,int>> pos(n);
    rep(y,h)rep(x,w){
        int a;
        cin>>a;
        pos[a] = {y,x};
    }

    vector<ll> cost(n);
    rep(i,n){
        if(i+d > h*w) continue;
        cost[i+d] = cost[i] + dist(pos[i],pos[i+d]);
    }

    cin>>q;
    rep(_,q){
        int l,r;
        cin>>l>>r;
        cout<<cost[r]-cost[l]<<endl;
    }
    return 0;
}

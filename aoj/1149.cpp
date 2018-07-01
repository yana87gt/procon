#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

using P = pair<int,int>;

int area(P c){
    return c.first*c.second;
}

namespace std {
    bool operator<(const P a, const P b) {
        return area(a) < area(b);
    }
}

pair<P,P> cut(P c,int s){
    int w = c.first, h = c.second;
    s %= (c.first+c.second)*2;
    P p1,p2;
    if(s < w){
        p1 = {s,h}, p2 = {w-s,h};
    }else if(s < w+h){
        s -= w;
        p1 = {w,s}, p2 = {w,h-s};
    }else if(s < w*2+h){
        s -= w+h;
        p1 = {s,h}, p2 = {w-s,h};
    }else{
        s -= w*2+h;
        p1 = {w,s}, p2 = {w,h-s};
    }
    return minmax(p1,p2);
}

int main(void){
    int N,W,H;
    while(cin>>N>>W>>H, N|W|H){
        vector<P> cake = {{W,H}};
        rep(i,N){
            int p,s;
            cin>>p>>s;
            p--;
            pair<P,P> cake_pair = cut(cake[p],s);
            cake.erase(cake.begin()+p);
            cake.push_back(cake_pair.first);
            cake.push_back(cake_pair.second);
        }
        sort(all(cake));
        rep(i,N+1){
            cout<<area(cake[i])<<(i<N ? " " : "\n");
        }
    }
    return 0;
}

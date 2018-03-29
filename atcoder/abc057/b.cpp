#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define INF 1e9
typedef long long ll;
typedef pair<int,int> P;
int dist(P a,P b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<P> p(n+1),c(m+1);
    rep1(i,n){
        cin>>p[i].first>>p[i].second;
    }
    rep1(i,m){
        cin>>c[i].first>>c[i].second;
    }
    rep1(i,n){
        int mdist = INF;
        int id = 0;
        rep1(j,m){
            if(mdist > dist(p[i],c[j])){
                mdist = dist(p[i],c[j]);
                id = j;
            }
        }
        cout<<id<<endl;
    }
    return 0;
}

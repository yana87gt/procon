#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(x) (x).begin(),(x).end()
typedef pair< int,pair<int,int> > P;

void solve(int N){
    vector<int> s(N);
    rep(i,N)scanf("%d",&s[i]);
    sort(all(s),greater<int>());
    vector<P> ab;
    rep(i,N)rep(j,N){
        if(i>=j)continue;
        ab.push_back({s[i]+s[j],{s[i],s[j]}});
    }
    sort(all(ab));
    rep(i,N)rep(j,N){
        if(i==j)continue;
        int d=s[i],c=s[j];
        int left=lower_bound(all(ab),(P){d-c,{INT_MIN,INT_MIN}})-ab.begin();
        int right=lower_bound(all(ab),(P){d-c+1,{INT_MIN,INT_MIN}})-ab.begin();
        for(int k=left;k<right;k++){
            int a=ab[k].second.first,b=ab[k].second.second;
            if(a!=c && b!=c && a!=d && b!=d){
                printf("%d\n",d);
                return;
            }
        }
    }
    printf("no solution\n");
}

int main(void){
    int N;
    while(scanf("%d",&N),N)solve(N);
    return 0;
}

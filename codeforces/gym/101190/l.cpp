#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

#define SIZE 10000

ll len[SIZE][SIZE];
ll c[SIZE][SIZE];

void solve(int sum){
    for(int p=2; p<=sum; p++){
        for(int x=2; x<=p; x++){
            c[sum][p] += c[sum-p][x];
            len[sum][p] += len[sum-p][x] + c[sum-p][x]*(to_string(p).length()+3);
        }
    }
}

int main(void){
    ll a,b;
    cin>>a>>b;
    ll pos = 0;
    return 0;
}

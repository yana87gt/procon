#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
int n;
#define M 10000001
#define N 1000001
bool prime[M];

vector<int> group[M];
vector<int> factor[N];

int dfs(int l,int r){
    return l+r;

}

void init(){
    rep(i,M) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int p=2; p<=sqrt(M)+1;p++){
        if(!prime[p]) continue;
        for(int q=p*2; q<=M; q+=p){
            prime[q] = false;
        }
    }
}

void pb(vector<int> &v,int x){
    if(v.back() != x){
        v.push_back(x);
    }
}

int main(void){
    init();
    cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        for(int p=2;p<=a;p++){
            if(prime[a]){
                pb(group[a],i);
                pb(factor[i],a);
                break;
            }
            while(prime[p] && a%p == 0){
                pb(group[p],i);
                pb(factor[i],p);
                a /= p;
            }
        }
    }

    rep(i,n){
        for(auto p : factor[i]){
            int idx = lb(group[p],i);
        }
    }
    return 0;
}

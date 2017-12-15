#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;


bool prime(int n){
    int root = sqrt(n);
    for(int i=2;i<=root;++i)if(n%i==0)return false;
    return true;
}

int main(){
    int n=1,sum=0;
    rep(i,64){
        n++;
        while(!prime(n))n++;
        sum += n;
    }
    debug(sum);
    debug(n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

// X Y

// 取った 2i の半分iが奇数なら片方に奇数が
// 取った 2i の半分iが偶数なら片方に偶数が
// 足される

// 1 2 , 0 4
// 2 0
// 0 1



bool solve(ll x,ll y){

}

int main(void){
    ll x,y;
    cin>>x>>y;
    cout<<((solve(x,y)) ? "Alice" : "Brown")<<endl;
    return 0;
}

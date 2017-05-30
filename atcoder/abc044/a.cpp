#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{double x,y;};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}

int main(void){
    int N,K,X,Y;
    cin>>N>>K>>X>>Y;
    if(N>K)cout<<K*X+(N-K)*Y<<endl;
    else cout<<N*X<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9

int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int res = INF;
    rep(ab,max(x,y)+1){
        int sum = 0;
        sum += c*ab*2;
        sum += max(x-ab,0)*a;
        sum += max(y-ab,0)*b;
        res = min(res,sum);
    }
    cout<<res<<endl;
    return 0;
}

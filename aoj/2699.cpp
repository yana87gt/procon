#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const int INF = 1e9;

int main(void){
    int d,e;
    while(cin>>d>>e, d){
        double ans = INF;
        rep(x,d+1){
            int y = d - x;
            ans = min(ans, abs(sqrt(x*x+y*y)-e));
        }
        printf("%.10f\n",ans);
    }
    return 0;
}
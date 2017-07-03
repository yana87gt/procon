#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define INT_MAX 2147483647
int a[40000],dp[40000];

int main(void){
    int n,p;
    scanf("%d",&n);
    rep(i,n){
        scanf("%d",&p);
        rep(j,p)scanf("%d",&a[j]);
        fill(dp,dp+p,INT_MAX);
        rep(j,p){
            *lower_bound(dp,dp+p,a[j]) = a[j];
        }
        printf("%d\n",lower_bound(dp,dp+p,INT_MAX)-dp);
    }

    return 0;
}

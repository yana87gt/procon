#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF ll(1e13)
typedef long long ll;
#define sum first
#define tail second


int solve(){
    debug("\n");
    int N;
    cin>>N;
    vector<ll> w(N);
    rep(i,N){
        cin>>w[i];
    }
    using P = pair<ll,ll>;
    vector<P> dp(N+2, P{INF, INF});
    dp[0] = {0,0};
    rep(i,N){
        for(int j = N; j >= 1; j--){
            // tail replace
            if(dp[j].tail > w[i] && (dp[j].sum - dp[j].tail)<=w[i]*6){
                printf("tail replace i = %d, j=%d\n",i,j);
                dp[j].sum += -dp[j].tail+w[i];
                dp[j].tail = w[i];
            }

            // move from left
            if(dp[j-1].sum<=w[i]*6 && (dp[j-1].sum+w[i] < dp[j].sum) ){
                printf("right move i = %d, j=%d\n",i,j);
                dp[j].sum = dp[j-1].sum + w[i];
                dp[j].tail = w[i];
            }


            for(int k = 1; k <= N; k++){
                printf("(%lld,%lld) ",dp[k].sum, dp[k].tail );
            }
            printf("\n");

        }
    }
    rep(i,N){
        if(dp[N-i].sum < INF){
            return N-i;
        }
    }
    return 1;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        cout<<solve()<<endl;
    }
    return 0;
}

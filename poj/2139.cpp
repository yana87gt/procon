#include <iostream>
#include <algorithm>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(){
    int N,M,n,res=300;
    cin>>N>>M;
    int d[N+1][N+1],c[N+1];
    rep1(i,N)rep1(j,N)d[i][j]=300;
    rep1(_,M){
        cin>>n;
        rep1(i,n)cin>>c[i];
        rep1(i,n)rep1(j,n)d[c[i]][c[j]]=1;
    }

    rep1(k,N)rep1(i,N)rep1(j,N){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }

    rep1(i,N){
        int sum=d[i][i]=0;
        rep1(j,N)sum+=d[i][j];
        res=min(res,sum);
    }
    cout<<100*res/(N-1)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,M;
    while(cin>>N>>M,N|M){
        vector<int> h(N),w(M);
        rep(i,N)cin>>h[i];
        rep(i,M)cin>>w[i];
        map<int,int> cntH,cntW;
        rep(i,N){
            int sum=0;
            rep(j,N)if(i<=j){
                sum+=h[j];
                cntH[sum]++;
            }
        }
        rep(i,M){
            int sum=0;
            rep(j,M)if(i<=j){
                sum+=w[j];
                cntW[sum]++;
            }
        }
        int res=0;
        for(auto itH:cntH){
            int H=itH.first;
            res += cntH[H]*cntW[H];
        }
        cout<<res<<endl;
    }
    return 0;
}

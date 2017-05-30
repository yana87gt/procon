#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
bool prime[10001];

int main(void){
    rep1(i,10000)prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i<=10000;i++){
        if(prime[i]) for(int k=2;i*k<=10000;k++) prime[i*k]=false;
    }

    int N;
    while(cin>>N,N){
        int cnt=0;
        for(int i=2;i*i<=N || N>1;){
            if(prime[i] && N%i==0){
                N/=i;
                cnt++;
                continue;
            }
            i++;
            if(cnt>2)break;
        }
        cout<<(cnt==2 ? "YES" : "NO")<<endl;
    }

    return 0;
}

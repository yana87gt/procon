#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9


int main(void){
    int n,x;
    cin>>n>>x;
    int mn=INF,sum=0;
    rep(i,n){
        int m;
        cin>>m;
        mn = min(mn,m);
        sum += m;
    }
    cout<<n + (x-sum)/mn<<endl;
    return 0;
}

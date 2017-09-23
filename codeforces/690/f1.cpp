#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

vector<int> g[10010];

ll calc(int n){
    if(n<=1)return 0;
    else return (n-1)*n/2;
}

int main(void){
    int N;
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll res=0;
    rep1(i,N){
        res += calc(g[i].size());
    }
    cout<<res<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
    int H,W,N,a,b,dx[9]={-1,-1,-1,0,0,0,1,1,1},dy[9]={-1,0,1,-1,0,1,-1,0,1};
    cin>>H>>W>>N;
    ll cnt[10]={(ll)(H-2)*(W-2)};
    map<pair<int,int>,int> mp;
    rep(i,N){
        cin>>a>>b;
        rep(j,9){
            int x=a+dx[j],y=b+dy[j];
            if(x<=1 || x>=H || y<=1 || y>=W)continue;
            cnt[mp[{x,y}]++]--;
            cnt[mp[{x,y}]]++;
        }
    }
    rep(k,10)cout<<cnt[k]<<endl;
    return 0;
}

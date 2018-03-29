#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    map<int,int> cnt;
    rep(i,n){
        int a;
        cin>>a;
        cnt[a-1]++;
        cnt[a]++;
        cnt[a+1]++;
    }
    int res = 0;
    for(auto x:cnt){
        res = max(x.second,res);
    }
    cout<<res<<endl;
    return 0;
}

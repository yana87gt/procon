#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
map<int, int> mp;

int rec(int k,ll mask){
    if(k == 12){
        int ans = 12;
        mask |= mask<<24;
        rep(i,48)rep(j,i){
            if((mask&(1LL<<i)) && (mask&(1LL<<j))){
                ans = min(ans,i-j);
            }
        }
        return ans;
    }
    if(mp[k]==1){
        return max(rec(k+1,mask|(1<<k)),rec(k+1,mask|(1<<(24-k))));
    }else{
        return rec(k+1,mask);
    }
}

int solve(){
    int n;
    cin>>n;
    mp[0]++;
    rep(i,n){
        int d;
        cin>>d;
        mp[d]++;
        if(mp[d] >= 3) return 0;
    }
    if(mp[0] >= 2 || mp[12] >= 2) return 0;
    ll mask = 1;
    if(mp[12]==1) mask |= 1<<12;
    rep(i,12) if(mp[i]==2) mask |= (1<<i)|(1<<(24-i));
    return rec(1,mask);
}

int main(void){
    cout<<solve()<<endl;
    return 0;
}

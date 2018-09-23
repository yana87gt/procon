#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n-1) a[i+1] += a[i];

    ll res = a[n-1];
    int left = 0, right = 0;
    rep(m,n){
        while(left < m){
            if(a[left]>=a[m]-a[left]) break;
            left++;
        }
        right = max(right,m+1);
        while(right < n-1){
            if(a[right]-a[m]>=a[n-1]-a[right]) break;
            right++;
        }

        for(int l = max(left-1,0); l < min(m,left+1); l++){
            for(int r = max(right-1,m+1); r < min(right+1,n-1); r++){
                vector<ll> seg = {a[l],a[m]-a[l],a[r]-a[m],a[n-1]-a[r]};
                sort(all(seg));
                res = min(res, seg[3]-seg[0]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

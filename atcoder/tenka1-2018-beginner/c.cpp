#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    int l = 1, r = n-2;
    ll lv=a[0], rv=a[n-1];
    ll sum = rv - lv;
    while(l<=r){
        ll ds[4] = {abs(lv - a[l]), abs(lv - a[r]), abs(rv - a[l]), abs(rv - a[r])};
        int i = 0;
        ll dmax = 0;
        rep(j,4){
            if(dmax < ds[j]){
                dmax = ds[j];
                i = j;
            }
        }
        sum += dmax;
        if(i==0){
            lv = a[l];
            l++;
        }
        if(i==1){
            lv = a[r];
            r--;
        }
        if(i==2){
            rv = a[l];
            l++;
        }
        if(i==3){
            rv = a[r];
            r--;
        }
    }
    cout<<sum<<endl;

    return 0;
}

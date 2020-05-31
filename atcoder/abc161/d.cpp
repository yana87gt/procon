#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    vector<ll> lun[11];
    lun[1] = {1,2,3,4,5,6,7,8,9};
    for(int d = 2; d <= 10; d++){
        for (ll s : lun[d-1]){
            ll r = s%10;
            lun[d].push_back(s*10 + r);
            if (r < 9) lun[d].push_back(s*10 + r+1);
            if (r > 0) lun[d].push_back(s*10 + r-1);
        }
    }
    vector<ll> luns = {0};
    for(int d = 1; d <= 10; d++){
        for (ll s : lun[d]){
            luns.push_back(s);
        }
    }
    sort(all(luns));

    ll k;
    cin >> k;
    cout << luns[k] << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(all(a), greater<int>());
    int res = 0;
    rep(i,n){
        if(mp[a[i]] == 0) continue;
        int b = 1;
        while(true){
            b *= 2;
            if(b > a[i]) break;
        }
        mp[a[i]]--;
        if(mp[b-a[i]]){
            mp[b-a[i]]--;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}

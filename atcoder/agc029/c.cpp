#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int n;
vector<int> a;

int check(int m){
    map<int,int> mp;
    rep1(i,n-1){
        if(a[i-1] < a[i]) continue;
        if(m == 1) return false;
        int pos = a[i];
        while(true){
            if(mp[pos] < m - 1){
                mp[pos]++;
                mp.erase(mp.upper_bound(pos), mp.end());
                break;
            }
            pos--;
            if(pos == 0) return false;
        }
    }
    return true;
}

int main(void){
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a[i];
    int l = 0, r = n;
    while(l+1 < r){
        int m = (l+r)/2;
        if(check(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}

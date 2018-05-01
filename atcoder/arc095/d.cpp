#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int mx = *max_element(all(a));
    int mid = *min_element(all(a));
    int diff = mx/2-mid;
    rep(i,n){
        if( diff > abs(mx/2-a[i])){
            diff = abs(mx/2-a[i]);
            mid = a[i];
        }
    }
    printf("%d %d\n",mx, mid);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    bool ng = false;
    rep(i,n){
        cin>>a[i];
        if(i<a[i]) ng = true;
    }
    rep(i,n-1){
        if(a[i]+1 < a[i+1]){
            ng = true;
        }
    }
    if(ng){
        cout<<-1<<endl;
        return 0;
    }
    a.push_back(0);
    ll cost = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i]+1 != a[i+1]){
            cost += a[i];
        }
    }
    cout<<cost<<endl;
    return 0;
}

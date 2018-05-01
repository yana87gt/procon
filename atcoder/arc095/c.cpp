#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    rep(i,n){
        int x;
        cin>>x;
        a[i] = {x,i};
    }
    sort(all(a));
    vector<int> res(n);
    rep(i,n){
        int index = a[i].second;
        res[index] = (i>=n/2) ? a[n/2-1].first : a[n/2].first;
    }
    rep(i,n){
        cout<<res[i]<<endl;
    }

    return 0;
}
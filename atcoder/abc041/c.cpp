#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    rep(i,n){
        int x;
        cin >> x;
        v[i] = {x, i+1};
    }
    sort(all(v), greater<pair<int,int>>());
    rep(i,n){
        cout << v[i].second << endl;
    }
    return 0;
}

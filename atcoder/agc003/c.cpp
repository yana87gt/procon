#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> index;
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    map<int, bool> odd;
    rep(i,n) odd[b[i]] = (i % 2 == 1);
    int cnt = 0;
    rep(i,n) if ((i % 2 == 0) && odd[a[i]]) cnt++;
    cout << cnt << endl;
    return 0;
}

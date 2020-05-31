#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    using Act = pair<pair<int,int>, int>; 
    vector<Act> v;
    rep(i,n) {
        int s,e;
        cin >> s >> e;
        v.push_back({{s,e},i});
    }
    sort(all(v));
    string res(n,' ');
    int last1 = 0, last2 = 0;
    rep(i,n){
        int s = v[i].first.first;
        int e = v[i].first.second;
        int id = v[i].second;
        if (last1 <= s) {
            last1 = e;
            res[id] = 'C';
        } else if (last2 <= s) {
            last2 = e;
            res[id] = 'J';
        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << res << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}

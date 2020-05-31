#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }


void solve(){
    int R, S;
    cin >> R >> S;
    vector<int> a;
    rep(s,S)rep(r,R){
        a.push_back(r);
    }
    vector<pair<int,int>> res;
    while(true){
        // print(a);
        bool is_sorted = true;
        rep(i,R*S-1){
            if (a[i] > a[i+1]) {
                is_sorted = false;
            }
        }
        if (is_sorted) break;
        int l = -1, r = -1;
        for (int i = R*S - 2; i >=0 ; i--) {
            if (a[i] == a[0] && a[i] != a[i+1]) {
                r = i+1;
                break;
            }
        }
        for (int i = 1; i < R*S ; i++) {
            if (a[i] == a[r]) {
                l = i+1;
                break;
            }
        }
        // TODO: l >= r このあたりの理由づけ
        if (l >= r && a[0] == a.back()) {
            l = find(all(a), 0) - a.begin();
            r = find(a.begin() + l, a.end(), a.back()) - a.begin();
        }
        // debug(l); debug(r-l);
        res.push_back({l,r-l});
        vector<int> nxt;
        for (int i = l; i < r; i++) {
            nxt.push_back(a[i]);
        }
        for (int i = 0; i < l; i++) {
            nxt.push_back(a[i]);
        }
        for (int i = r; i < R*S; i++) {
            nxt.push_back(a[i]);
        }
        a = move(nxt);
    }
    
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
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

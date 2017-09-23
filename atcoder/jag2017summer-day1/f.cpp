#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<int(n); ++i)
#define rrep(i,n) for(int i=int(n)-1; i>=0; --i)
#define INF 1e9

string s;
set<int> pos[26];

void solve(){
    string t;
    cin >> t;
    int m = t.size(), r = -1;
    rep(i,m) {
        r = *(pos[t[i]-'a'].upper_bound(r));
        if(r == INF){
            cout << -1 << endl;
            return;
        }
    }
    int l = r+1;
    rrep(i,m){
        l = *(--pos[t[i]-'a'].lower_bound(l));
    }
    cout<<l+1<<" "<<r+1<<endl;
}

int main(){
    int q;
    cin>>s>>q;
    rep(i,s.size()) pos[s[i]-'a'].insert(i);
    rep(c,26) pos[c].insert(INF);
    rep(i,q) solve();
}
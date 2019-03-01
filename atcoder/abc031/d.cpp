#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int k, n;
vector<string> v,w;
map<char, string> mp;
bool rec(int y, int x, int z){
    if (y == n) return true;
    if (x == (int)v[y].size()) {
        if (z == (int)w[y].size()) {
            return rec(y+1, 0, 0);
        } else {
            return false;
        }
    }
    if (z >= (int)w[y].size()) {
        return false;
    }
    if (mp[v[y][x]] != "") {
        int len = mp[v[y][x]].size();
        if (w[y].substr(z,len) == mp[v[y][x]]) {
            return rec(y,x+1,z+len);
        } else {
            return false;
        }
    }
    rep1(len,3){
        mp[v[y][x]] = w[y].substr(z,len);
        if (rec(y,x+1,z+len)) {
            return true;
        } else {
            mp.erase(v[y][x]);
        }
    }
    return false;
}

int main(void){
    cin >> k >> n;
    v.resize(n);
    w.resize(n);
    rep(i,n){
        cin >> v[i] >> w[i];
    }
    rec(0,0,0);
    rep1(i,k){
        cout << ((mp['0'+i] == "") ? "wow" : mp['0'+i]) << endl;
    }
    return 0;
}

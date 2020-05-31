#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
vector<int> get_acum(string s, char c){
    vector<int> acum = {0};
    rep(i,s.size()){
        acum.push_back(acum.back() + (s[i] == c));
    }
    return acum;
}

int main(void){
    int n;
    string s;
    cin >> n >> s;
    vector<int> acum[3];
    acum[0] = get_acum(s, 'R');
    acum[1] = get_acum(s, 'B');
    acum[2] = get_acum(s, 'G');
    map<char,int> mp = {{'R', 0}, {'B', 1}, {'G', 2}};
    ll sum = 0;
    rep(j,n)rep(i,j){
        if (s[i] == s[j]) continue;
        int c = 3 - mp[s[i]] - mp[s[j]];
        sum += acum[c][n] - acum[c][j];
        int k = j+(j-i);
        if (k < n && mp[s[k]] == c) sum--;
    }
    cout << sum << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    map<string, int> index;
    vector<int> t(n);
    rep(i,n){
        string s;
        cin >> s >> t[i];
        index[s] = i+1;
    }
    string x;
    cin >> x;
    int sum = 0;
    for (int i = index[x]; i < n; i++) {
        sum += t[i];
    }
    cout << sum << endl;
    return 0;
}

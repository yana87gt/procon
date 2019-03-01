#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
const int INF = 1e9;

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    int d = INF;
    rep(i,n-2){
        string sub = s.substr(i,3);
        int x = stoi(sub);
        d = min(d, abs(x-753));
    }
    cout << d <<endl;
    return 0;
}

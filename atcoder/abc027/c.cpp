#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    bitset<64> bs(n);
    string s = bs.to_string();
    s = s.substr(s.find("1")+1);
    int m = s.size();
    int win = -1;
    rep(i,m){
        if (((m-i) & 1) == (s[i] == '1')){
            win = i;
            break;
        }
    }
    if (win == -1) {
        cout<<((m&1) ? "Takahashi" : "Aoki")<<endl;
    } else {
        cout<<((win%2==0) ? "Takahashi" : "Aoki")<<endl;
    }
    return 0;
}

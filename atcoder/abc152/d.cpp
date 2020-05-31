#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    rep1(i,n){
        string s = to_string(i);
        mp[{s.back()-'0', s.front()-'0'}]++;
    }
    ll sum = 0;
    rep1(i,n){
        string s = to_string(i);
        sum += mp[{s.front()-'0', s.back()-'0'}];
    }
    cout << sum << endl;
    return 0;
}

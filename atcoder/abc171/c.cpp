#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    string s;
    while (n) {
        s += 'a' + ((n-1) % 26);
        n = (n-1)/26;
    }
    reverse(all(s));
    cout << s << endl;
    return 0;
}

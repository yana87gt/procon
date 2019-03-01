#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

vector<int> children[20];
ll dp[20];

ll calc(int x){
    if (dp[x]) return dp[x];
    vector<ll> s;
    if ((int)children[x].size() == 0) {
        return dp[x] = 1;
    }
    for(int child : children[x]){
        s.push_back(calc(child));
    }
    sort(all(s));
    return dp[x] = s.front() + s.back() + 1;
}

int main(void){
    int n;
    cin >> n;
    rep1(i,n-1) {
        int p;
        cin >> p;
        p--;
        children[p].push_back(i);
    }
    cout << calc(0) << endl;

    return 0;
}

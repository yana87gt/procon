#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int res = 0;
    int SIZE = 1000010;
    vector<bool> multi(SIZE);
    for(auto itr : mp){
        int x = itr.first;
        int cnt = itr.second;
        if (multi[x]) continue;
        for(int y = x; y < SIZE; y += x){
            multi[y] = true;
        }
        if (cnt == 1) res++;
    }
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int a[1010][1010] = {};
    int head[1010] = {};

    rep(i,n){
        rep(j,n-1){
            int x;
            cin >> x;
            x--;
            a[i][j] = x;
        }
    }
    int turn = 0;
    vector<int> used(n, -1);
    while(true){
        bool ng = true;
        int empty_cnt = 0;
        rep(i,n){
            if (head[i] == n-1) {
                empty_cnt++;
                continue;
            }
            int j = a[i][head[i]];
            if (used[i] == turn || used[j] == turn) continue;
            if (a[j][head[j]] == i) {
                head[i]++;
                head[j]++;
                used[i] = used[j] = turn;
                ng = false;
            }
        }
        if (empty_cnt == n) break;
        if (ng) {
            cout << -1 << endl;
            return 0;
        }
        turn++;
    }
    cout << turn << endl;

    return 0;
}

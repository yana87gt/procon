#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin >> n;
    vector<deque<int>> t(n);
    rep(i,n) {
        int k;
        cin >> k;
        t[i] = deque<int>(k);
        rep(j,k){
            cin >> t[i][j];
        }
    }
    map<int,int> mp1, mp2;
    rep(i,n){
        mp1[t[i][0]] = i;
        if ((int)t[i].size() > 1) {
            mp2[t[i][1]] = i;
        }
    }
    int m;
    cin >> m;
    rep(i,m){
        int a;
        cin >> a;
        auto top1 = mp1.rbegin();
        auto top2 = mp2.rbegin();
        if (top2 == mp2.rend()) a = 1;
        if (a == 2 && top2->first > top1->first) {
            cout << top2->first << endl;
            int x = top2->second; 
            int t1 = t[x][0];
            int t2 = t[x][1];
            t[x].pop_front();
            t[x].pop_front();
            mp2.erase(t2);
            if (t[x].size()) {
                mp2[t[x].front()] = x;
            }
            t[x].push_front(t1);
        } else {
            cout << top1->first << endl;
            int x = top1->second;
            int t1 = t[x][0];
            t[x].pop_front();
            mp1.erase(t1);
            if (t[x].size()) {
                int t2 = t[x][0];
                mp2.erase(t2);
                mp1[t2] = x;
                if ((int)t[x].size() >= 2) {
                    mp2[t[x][1]] = x;
                }
            }
        }
    }

    return 0;
}

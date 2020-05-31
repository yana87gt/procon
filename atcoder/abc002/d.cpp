#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool g[15][15];
int n, m;

bool check(vector<int> &choice){
    for(int x : choice){
        for(int y : choice){
            if (x == y) continue;
            if (!g[x][y]) return false;
        }
    }
    return true;
}

bool rec(int k, int index, vector<int> &choice){
    if (index == n){
        if((int)choice.size() == k) {
            if(check(choice)) return true;
        }
        return false;
    }
    if ((int)choice.size() == k) {
        return rec(k, index+1, choice);
    }
    if (rec(k, index+1, choice)) return true;
    choice.push_back(index);
    if (rec(k, index+1, choice)) return true;
    choice.pop_back();
    return false;
}

int main(void){
    cin >> n >> m;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x][y] = g[y][x] = true;
    }
    for(int k = n; k > 0; k--){
        vector<int> choice;
        if(rec(k, 0, choice)){
            cout << k << endl;
            break;
        }
    }
    return 0;
}

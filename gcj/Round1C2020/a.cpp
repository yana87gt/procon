#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

void solve(){
    int x,y;
    cin >> x >> y;
    string command;
    cin >> command;
    int n = command.size();
    rep(i,n){
        if (command[i] == 'N') y++;
        if (command[i] == 'S') y--;
        if (command[i] == 'E') x++;
        if (command[i] == 'W') x--;
        int dist = abs(x) + abs(y);
        if (i+1 >= dist) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        solve();
    }
    return 0;
}

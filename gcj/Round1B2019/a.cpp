#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int n, Q;
        cin >> n >> Q;
        map<char, vector<int>> cum;
        cum['N'].resize(Q+1);
        cum['S'].resize(Q+1);
        cum['E'].resize(Q+1);
        cum['W'].resize(Q+1);
        rep(i,n){
            int x,y;
            char dir;
            cin >> x >> y >> dir;
            if (dir == 'S') {
                cum[dir][y-1]++;
            }
            if (dir == 'N') {
                cum[dir][y+1]++;
            }
            if (dir == 'W') {
                cum[dir][x-1]++;
            }
            if (dir == 'E') {
                cum[dir][x+1]++;
            }
        }
        rep(i,Q){
            int j = Q - i;
            cum['N'][i+1] += cum['N'][i];
            cum['E'][i+1] += cum['E'][i];
            cum['S'][j-1] += cum['S'][j];
            cum['W'][j-1] += cum['W'][j];
        }
        int maxX = 0, maxY = 0, resX = 0, resY = 0;
        rep(i,Q+1){
            if (maxX < cum['E'][i]+cum['W'][i]) {
                maxX = cum['E'][i]+cum['W'][i];
                resX = i;
            }
            if (maxY < cum['S'][i]+cum['N'][i]) {
                maxY = cum['S'][i]+cum['N'][i];
                resY = i;
            }
        }
        printf("Case #%d: %d %d\n",_+1, resX, resY);
        
    }
    return 0;
}

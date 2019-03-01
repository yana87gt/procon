#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int X,Y,n;
    cin >> X >> Y >> n;
    vector<int> block(X+2, Y+1);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        block[x] = min(block[x], y);
    }
    int maxY = 1;
    for(int x = 2; x <= X; x++){
        if(block[x] <= maxY){
            cout << x - 1 << endl;
            return 0;
        }
        if(block[x] > maxY + 1){
            maxY++;
        }
    }
    cout << X << endl;
    return 0;
}

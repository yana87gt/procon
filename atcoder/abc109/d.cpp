#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int a[502][502];

int main(void){
    int Y,X;
    cin >> Y >> X;
    rep1(y,Y)rep1(x,X){
        cin >> a[y][x];
    }
    vector<vector<int>> res;
    rep1(y,Y)rep1(x,X){
        if (y==Y && x==X) continue;
        if (a[y][x]&1) {
            if (x < X) {
                a[y][x+1] ++;
                res.push_back({y,x,y,x+1});
            } else {
                a[y+1][x] ++;
                res.push_back({y,x,y+1,x});
            }
        }
    }
    cout<<res.size()<<endl;
    rep(i,res.size()){
        rep(j,4){
            cout<<res[i][j]<<(j<3 ? " " : "\n");
        }
    }

    return 0;
}

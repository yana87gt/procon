#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,m,X,Y;
    cin>>n>>m>>X>>Y;
    int maxX = -100, minY = 100;
    rep(i,n){
        int x;
        cin>>x;
        maxX = max(maxX, x);
    }
    rep(i,m){
        int y;
        cin>>y;
        minY = min(minY, y);
    }
    cout<<((max(X,maxX)<min(Y,minY)) ? "No War" : "War")<<endl;
    return 0;
}

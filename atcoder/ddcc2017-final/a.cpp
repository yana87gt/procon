#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef complex<double> Point;

int solve(int k,int r){
    int sum = 0;
    rep(x,r*2/k)rep(y,r*2/k){
        bool ok = true;
        rep(dx,2)rep(dy,2){
            ok &= abs(Point((x+dx)*k,(y+dy)*k)-Point(r,r))<=r;
        }
        if(ok) sum++;
    }
    return sum;
}

int main(void){
    int k;
    cin>>k;
    cout<<solve(k,100)<<" "<<solve(k,150)<<endl;
}

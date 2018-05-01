#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int h = ty-sy, w = tx-sx;
    rep(i,h)cout<<'U';
    rep(i,w)cout<<'R';
    rep(i,h)cout<<'D';
    rep(i,w+1)cout<<'L';
    rep(i,h+1)cout<<'U';
    rep(i,w+1)cout<<'R';
    cout<<"DR";
    rep(i,h+1)cout<<'D';
    rep(i,w+1)cout<<'L';
    cout<<"U"<<endl;
    return 0;
}

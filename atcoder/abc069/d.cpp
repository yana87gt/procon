#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int h,w,n;
    cin>>h>>w>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int b[100][100];
    int y=0,x=0;
    rep(i,n){
        while(a[i]>0){
            b[y][x] = i+1;
            if(y%2==0) x++;
            else x--;
            if(x==w) x--,y++;
            if(x==-1) x++,y++;
            a[i]--;
        }
    }

    rep(i,h)rep(j,w){
        cout<<b[i][j]<<(j<w-1 ? " " : "\n");
    }
    return 0;
}

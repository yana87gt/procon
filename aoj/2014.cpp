#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int a[52][52];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int cnt[4];
/*  .->0  b,w,b&w->1,2,3  B,W->10,20  WALL->30  */

void paint(int y,int x,int color){
    if(a[y][x]>=3 || a[y][x]==color)return;
    cnt[a[y][x]]--;
    a[y][x] |= color;
    cnt[a[y][x]]++;
    rep(i,4)paint(y+dy[i],x+dx[i],a[y][x]);
}

int main(void){
    int h,w;
    char c;
    while(cin>>w>>h, w|h){
        rep(i,4)cnt[i]=0;
        rep1(y,h){
            rep1(x,w){
                cin>>c;
                if(c=='.')a[y][x] = 0;
                else a[y][x] = (c=='B' ? 10 : 20);
            }
        }
        rep(y,h+2) a[y][0] = a[y][w+1] = 30;
        rep(x,w+2) a[0][x] = a[h+1][x] = 30;

        rep1(y,h)rep1(x,w)if(a[y][x]>=10)rep(i,4)paint(y+dy[i],x+dx[i],a[y][x]/10);

        cout<<cnt[1]<<" "<<cnt[2]<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
struct point{int x,y;};

int main(void){
    int D,N;
    cin>>D;
    while(D--){
        cin>>N;
        point p[N];
        rep(i,N)cin>>p[i].x>>p[i].y;

        int maxcnt=0;
        rep(i,N){
            rep(j,N){
                if(i==j)continue;
                int cnt=0;
                rep(k,N)if((p[i].y-p[k].y)*(p[i].x-p[j].x)==(p[i].x-p[k].x)*(p[i].y-p[j].y))cnt++;
                maxcnt = max(maxcnt,cnt);
            }
        }
        cout<<maxcnt<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl

int main(void){
    int d,w;
    while(cin>>d>>w,d|w){
        int e[10][10]={};
        rep(y,d)rep(x,w)cin>>e[y][x];

        int res=0;
        rep(ly,d)for(int ry=ly+2;ry<d;ry++){
            rep(lx,w)for(int rx=lx+2;rx<w;rx++){
                
                int in=-1,out=11,sum=0;
                for(int y=ly;y<=ry;y++){
                    for(int x=lx;x<=rx;x++){
                        if(y==ly || y==ry || x==lx || x==rx){
                            out = min(out,e[y][x]);
                        }else{
                            in = max(in,e[y][x]);
                            sum += e[y][x];
                        }
                    }
                }
                if(out<=in)continue;
                res = max(res,(rx-lx-1)*(ry-ly-1)*out-sum);

            }
        }

        cout<<res<<endl;
    }
    return 0;
}

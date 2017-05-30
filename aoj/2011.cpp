#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)
int main(void){
    int n;
    while(cin>>n,n){
        bool sc[51][31]={};//[man][date]
        bool piece[51][51]={};
        int ans=-1;
        rep1(i,n){
            int f,date;
            cin>>f;
            rep1(j,f){
                cin>>date;
                sc[i][date]=true;
            }
        }
        rep1(i,n)piece[i][i]=true;

        rep1(date,30){
            rep1(i,n)rep1(j,n){
                if(sc[i][date] && sc[j][date]){
                    rep1(k,n)piece[j][k]=piece[i][k]|=piece[j][k];
                }
            }
            rep1(i,n){
                bool gather=true;
                rep1(j,n) gather &= piece[i][j];
                if(gather){
                    ans=date;
                    break;
                }
            }
            if(ans>0)break;
        }
        cout<<ans<<endl;
    }

    return 0;
}

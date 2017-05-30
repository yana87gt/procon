#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)
#define repr(i,n) for(int i=n;i>0;--i)
#define W 5

int main(void){
    int a[11][W+2]={};
    int cnt=1,score,H;

    while(cin>>H, H){
        score=0;
        rep1(j,H)rep1(i,W)cin>>a[j][i];

        while(1){
            bool combo=false;

            /*石を消滅・スコアカウント*/
            repr(j,H){
                rep1(i,W){
                    //空きでなく右と同じなら
                    if(a[j][i] && (a[j][i]==a[j][i+1]))++cnt;
                    else{
                        if(cnt>=3){
                            score+=a[j][i]*cnt;
                            combo=true;
                            //消滅したところに0を入れる
                            while(cnt--)a[j][i-cnt]=0;
                        }
                        cnt=1;
                    }
                }
            }

            if(!combo || H==1)break;

            /*石を落下*/
            repr(j,H){
                rep1(i,W){
                    if(!a[j][i]){
                        repr(k,j-1){
                            if(a[k][i]){
                                a[j][i]=a[k][i];
                                a[k][i]=0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout<<score<<endl;
    }

    return 0;
}

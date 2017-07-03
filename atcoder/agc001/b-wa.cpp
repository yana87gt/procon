#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(void){
    ll N,X,cnt=0;
    bool finish=false;
    cin>>N>>X;
    ll a1=X,a2=N,b1=0,b2=N,c1=0,c2=N;
    ll a=X,b=N-X,c=N,dir=1;
    while(!finish)
    {
        if(dir==1){
            if(b2-b<c-c1){
                c1=c=c-(b2-b);
                cnt+=(b2-b);
                b=b2;
                dir=3;
            }else{
                b1=b=b+(c-c1);
                cnt+=(c-c1);
                c=c1;
                dir=2;
            }
        }

        if(dir==2){
            if(c2-c==a-a1){
                finish=true;
                cnt+=a-a1;
            }
            else if(c2-c<a-a1){
                a2=a=a-(c2-c);
                cnt+=(c2-c);
                c=c2;
                dir=1;
            }else{
                c1=c=c+(a-a1);
                cnt+=(a-a1);
                a=a1;
                dir=3;
            }
        }

        if(dir==3){
            b1=b=b-(a2-a);
            cnt+=(a2-a);
            a=a2;
            dir=2;
        }
    }
    cout<<cnt<<endl;


    return 0;
}

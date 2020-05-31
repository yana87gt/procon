#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int T,l,r,n;
    cin>>T;
    rep(_,T){
        cin>>l>>r>>n;
        rep(__,n){
            int mid = (l+r)/2;
            cout<<mid<<endl<<flush;
            string s;
            cin>>s;
            if(s=="CORRECT"){
                break;
            }
            if(s=="TOO_BIG"){
                r = mid;
            }else{
                l = mid+1;
            }
        }
    }
    return 0;
}

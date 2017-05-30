#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main(void){
    int a,b,c,t=0;
    cin>>a>>b>>c;

    rep(i,61){
        if(t%60<=c && c<=t%60+a){
            cout<<t-t%60+c<<endl;
            return 0;
        }
        t+=(a+b);
    }

    cout<<-1<<endl;

    return 0;
}

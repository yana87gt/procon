#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int solve(string T){
    int res=0,cnt=0;
    rep(i,T.size()){
        if((cnt%2==0 && T[i]=='2')||(cnt%2==1 && T[i]=='5'))cnt++;
        else if(T[i]=='2')cnt=1;
        else cnt=0;
        res = max(res,cnt);
    }
    return res-res%2;
}

int main(void){
    string T;
    cin>>T;
    string T1=T,T2=T;
    string nico="25";
    rep(i,T.size()){
        if(T[i]=='?'){
            T1[i]=nico[i%2];
            T2[i]=nico[(i+1)%2];
        }
    }
    cout<<max(solve(T1),solve(T2))<<endl;
    return 0;
}

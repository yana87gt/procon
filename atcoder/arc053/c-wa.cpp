#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main(void){
    int N,a,b,top=0,cnt1=0,cnt2=0,result=0;
    cin>>N;
    pair<int,int> cold[N];
    pair<int,int> hot[N];
    rep(i,N){
        cin>>a>>b;
        if(a<b)cold[cnt1++]=pair<int,int>(a,b);
        else hot[cnt2++]=pair<int,int>(b,a);
    }
    sort(cold,cold+cnt1);
    sort(hot,hot+cnt2);
    rep(i,cnt1){
        result+=cold[i].first;
        top=max(top,result);
        result-=cold[i].second;
    }
    for(int i=cnt2-1;i>=0;i--){
        result+=hot[i].second;
        top=max(top,result);
        result-=hot[i].first;
    }
    cout<<top<<endl;

    return 0;
}

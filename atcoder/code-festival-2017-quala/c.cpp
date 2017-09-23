#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int H,W;
    cin>>H>>W;
    vector<string> a(H);
    rep(y,H) cin>>a[y];
    int cnt[26]={};
    rep(y,H)rep(x,W) cnt[a[y][x]-'a']++;
    int set4=0,set2=0;
    rep(c,26){
        set4 += cnt[c]/4;
        if((cnt[c]%4)>=2) set2++;
    }
    set4 -= (H/2)*(W/2);
    if(set4>=0 && set2+set4*2 == (W%2)*(H/2)+(H%2)*(W/2)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

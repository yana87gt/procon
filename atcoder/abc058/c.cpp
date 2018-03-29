#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> mina(26,50);
    rep(i,n){
        string s;
        cin>>s;
        int cnt[26]={};
        for(char c : s){
            cnt[c-'a']++;
        }
        rep(j,26){
            mina[j] = min(cnt[j],mina[j]);
        }
    }
    rep(i,26){
        cout<<string(mina[i],'a'+i);
    }
    cout<<endl;
    return 0;
}

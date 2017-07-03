#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N;
    string s,t;
    cin>>N>>s>>t;
    int res = N*2;
    rep(i,N){
        if(s.substr(i,N-i)==t.substr(0,N-i)){
            res-=N-i;
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}

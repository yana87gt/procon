#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,S,T,cnt=0;
    cin>>N>>S>>T;
    while(S<=T){
        if(S==T){
            cout<<cnt<<endl;
            return 0;
        }
        T/=2;
        cnt++;
    }
    cout<<-1<<endl;
    return 0;
}

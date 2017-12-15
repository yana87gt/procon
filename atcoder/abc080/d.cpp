#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define T 100005
bool ch[31][T];
int a[T];

int main(void){
    int N,C;
    cin>>N>>C;
    rep(_,N){
        int s,t,c;
        cin>>s>>t>>c;
        for(int i=s;i<=t;i++){
            ch[c][i]=true;
        }
    }
    int res=0;
    rep(k,C+1){
        rep(i,T){
            if(ch[k][i]){
                a[i]++;
                res = max(a[i],res);
            }
        }
    }
    cout<<res<<endl;

    return 0;
}

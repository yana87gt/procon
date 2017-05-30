#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    int N,Q,l,r,state=0;
    cin>>N>>Q;

    int *a = new int[N+2];
    rep(i,N+2)a[i]=0;

    rep(i,Q){
        cin>>l>>r;
        ++a[l];
        --a[r+1];
    }

    rep1(i,N){
        state += a[i];
        cout<<(state%2);
    }
    cout<<endl;

    return 0;
}

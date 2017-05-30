#include <bits/stdc++.h>
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    int N,Q,L,R,T;
    cin>>N>>Q;
    int a[101]={};
    rep1(i,Q){
        cin>>L>>R>>T;
        for(int j=L;j<=R;j++)a[j]=T;
    }
    rep1(i,N)cout<<a[i]<<endl;
    return 0;
}

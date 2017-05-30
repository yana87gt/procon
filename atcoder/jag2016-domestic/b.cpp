#include <bits/stdc++.h>
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    int N,M,T;
    cin>>N>>M>>T;
    int *a = new int[N+1];
    rep1(i,N)cin>>a[i];

    int study=a[1]-M;
    rep1(i,N-1)study += max(a[i+1]-a[i]-2*M,0);
    study += max(T-a[N]-M,0);

    cout<<study<<endl;

    return 0;
}

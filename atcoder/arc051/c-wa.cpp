#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long ll;

int main(void){
    int N;
    ll A,B;
    cin>>N>>A>>B;
    ll *a = new ll[N+1];
    rep(i,N)cin >> a[i];

    sort(a,a+N);
    while(a[0]*=A,a[0]<a[N-1]){
        sort(a,a+N);
        B--;
        if(B==0){
            rep(i,N)cout<<a[i]<<endl;
            return 0;
        }

    }

    return 0;
}

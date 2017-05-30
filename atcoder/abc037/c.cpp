#include <bits/stdc++.h>
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;

int main(void){
    int N,K;
    ll allsum,partsum=0;
    cin>>N>>K;
    int *a = new int[N+1];
    rep1(i,N){
        scanf("%d",&a[i]);
        partsum+=a[i];
        if(i>K){
            partsum-=a[i-K];
            allsum+=partsum;
        }else if(i==K)allsum=partsum;
    }

    cout<<allsum<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int N,M;
    while(cin>>N>>M,N|M){
        vector<int> a(M+1);
        rep(i,N){
            int d,v;
            cin>>d>>v;
            a[d]=max(a[d],v);
        }
        int sum=0;
        rep1(i,M)sum+=a[i];
        cout<<sum<<endl;
    }
    return 0;
}

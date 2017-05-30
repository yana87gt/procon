#include <bits/stdc++.h>
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    int N;
    cin>>N;
    int m=N;
    rep1(i,sqrt(N))m=min(N/i-i+N%i,m);
    cout<<m<<endl;
    return 0;
}

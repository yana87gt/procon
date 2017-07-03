#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=n;++i)

int main(void){
    int N,x;
    cin>>N>>x;
    if(x==1 || x==2*N-1)cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        rep1(i,2*N-1)cout<<(x+N+i-2)%(2*N-1)+1<<endl;
    }
    return 0;
}

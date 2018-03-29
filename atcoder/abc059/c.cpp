#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
vector<ll> a;
int N;

ll sovle(ll sum,ll cost){
    rep1(i,N-1){
        if(sum*(sum+a[i])<0)sum+=a[i];
        else{
            cost+=abs(sum+a[i])+1;
            sum=(sum>0?-1:1);
        }
    }
    return cost;
}

int main(){
    cin>>N;
    a.resize(N);
    rep(i,N)cin>>a[i];
    if(a[0]==0){
        cout<<min(sovle(1,1),sovle(-1,1))<<endl;
    }else{
        cout<<min(sovle(a[0],0),sovle((a[0]>0?-1LL:1LL),abs(a[0])+1))<<endl;
    }
}

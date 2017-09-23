#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    sort(all(a));
    int cnt=0;
    ll area=1;
    for(int i=N-1;i>0;i--){
        if(a[i]==a[i-1]){
            area*=a[i];
            i--;
            cnt++;
        }
        if(cnt==2)break;
    }

    if(cnt<2)cout<<0<<endl;
    else cout<<area<<endl;

    return 0;
}

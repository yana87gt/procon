#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int main(void){
    int N;
    cin>>N;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    int sum=0,res=0,l=0;
    rep(r,N){
        sum+=a[r];
        if(sum==N)res++;
        while(sum>=N)sum-=a[l],l++;
    }
    cout<<res<<endl;
    return 0;
}

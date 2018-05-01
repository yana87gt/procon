#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()

int main(void){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(m);
    rep(i,m)cin>>a[i];
    int pos = lb(a,x);
    cout<<min(pos, m-pos)<<endl;
    return 0;
}

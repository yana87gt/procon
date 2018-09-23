#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(),(a).end()

using P = pair<int,int>;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<P> v(m);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        v[i] = P(a,b);
    }
    sort(all(v));
    int end = 0;
    int res = 0;
    rep(i,m){
        int a = v[i].first;
        int b = v[i].second;
        if(end <= a){
            res++;
            end = b;
        }else{
            end = min(end,b);
        }
    }
    cout<<res<<endl;
    return 0;
}

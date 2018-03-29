#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

bool solve(){
    int n;
    cin>>n;
    vector<int> t(n+1),x(n+1),y(n+1);
    rep1(i,n){
        cin>>t[i]>>x[i]>>y[i];
    }
    rep1(i,n){
        int cost = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        int dt = t[i]-t[i-1];
        if(dt<cost || (dt-cost)&1){
            return false;
        }
    }
    return true;
}

int main(void){
    cout<<((solve()) ? "Yes" : "No")<<endl;
    return 0;
}

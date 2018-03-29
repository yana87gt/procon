#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> c(n),s(n),f(n);
    rep(i,n-1){
        cin>>c[i]>>s[i]>>f[i];
    }
    rep(i,n){
        int t = 0;
        for(int j=i;j<n-1;j++){
            t=max(t,s[j]);
            if(t%f[j]==0){
                t += c[j];
            }else{
                t += f[j]-t%f[j] + c[j];
            }
        }
        cout<<t<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int cnt = 0;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cnt++;
            i++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

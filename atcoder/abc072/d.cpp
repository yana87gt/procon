#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int cnt=0;
    rep(i,n-1){
        if(p[i] == i+1){
            swap(p[i],p[i+1]);
            cnt++;
        }
    }
    if(p[n-1] == n){
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

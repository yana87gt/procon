#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    int cnt = 0;
    int pos = 0;
    while(pos<n-1){
        pos += k-1;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

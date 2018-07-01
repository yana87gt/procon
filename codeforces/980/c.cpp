#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    vector<int> lside(256),rside(256);
    rep(i,256) lside[i] = rside[i] = i;
    rep(i,n){
        if(lside[p[i]] != rside[p[i]]) continue;
        int l = max(p[i]-k+1,0);
        if(lside[l] != l){
            l = rside[l]+1;
        }
        for(int j=l; j<=p[i]; j++){
            lside[j] = l;
            rside[j] = p[i];
        }
    }
    rep(i,n){
        cout<<lside[p[i]]<<(i==n-1 ? "\n": " ");
    }
    return 0;
}

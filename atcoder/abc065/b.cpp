#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    int x=0;
    rep(i,n){
        if(x==1){
            cout<<i<<endl;
            return 0;
        }
        x=a[x];
    }
    cout<<-1<<endl;
    return 0;
}

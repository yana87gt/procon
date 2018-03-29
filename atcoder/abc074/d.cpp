#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    int a[300][300];
    bool del[300][300]={};
    cin>>n;
    rep(i,n)rep(j,n) cin>>a[i][j];
    long long sum = 0;
    rep(k,n)rep(i,n)rep(j,n)if(i!=j && i!=k && j!=k){
        if(a[i][j] > a[i][k] + a[k][j]){
            cout<<-1<<endl;
            return 0;
        }
        if(a[i][j] == a[i][k] + a[k][j]){
            del[i][j] = true;
        }
    }
    rep(i,n)rep(j,i)if(!del[i][j])sum += a[i][j];
    cout<<sum<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int N,K;
    cin>>N>>K;
    vector<int> a(N);
    rep(i,N){
        cin>>a[i];
    }
    sort(all(a));
    reverse(all(a));
    int sum = 0;
    rep(i,N){
        sum += a[i];
        if(sum>=K){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}

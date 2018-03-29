#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define INF 1e9
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    ll sum = 0, seq = 1;
    int pre = INF;

    rep(i,n){
        if(pre<a[i]){
            seq++;
        }else{
            seq = 1;
        }
        sum += seq;
        pre = a[i];
    }
    cout<<sum<<endl;

    return 0;
}

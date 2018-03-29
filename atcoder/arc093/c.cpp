#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n+2);
    ll sum = 0;
    int pre = 0;
    rep1(i,n){
        cin>>a[i];
        sum += abs(pre-a[i]);
        pre = a[i];
    }
    sum += abs(a[n]);
    rep1(i,n){
        cout<<sum - (abs(a[i-1]-a[i])+abs(a[i]-a[i+1])) + abs(a[i+1]-a[i-1])<<endl;
    }
    return 0;
}

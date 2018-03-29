#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    map<int,int> mp;
    rep(i,n){
        int x;
        cin>>x;
        mp[x]++;
    }
    ll sum = 0;
    for(auto itr:mp){
        int num = itr.first;
        int cnt = itr.second;
        if(num < cnt) sum += cnt-num;
        else if (num > cnt) sum += cnt;
    }
    cout<<sum<<endl;
    return 0;
}

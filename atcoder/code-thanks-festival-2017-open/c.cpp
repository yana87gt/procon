#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n),b(n),s(n);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    rep(i,n){
        cin>>a[i]>>b[i];
        s[i]++;
        pq.push({a[i],i});
    }
    ll sum = 0;
    rep(i,k){
        pair<ll,int> top = pq.top();
        pq.pop();
        sum += top.first;
        int id = top.second;
        s[id]++;
        pq.push({a[id]+(s[id]-1)*b[id],id});
    }
    cout<<sum<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<bool> del(n);
    ll sum[2] = {};
    rep(i,n){
        cin>>a[i];
        if(a[i]>0) sum[i%2] += a[i];
        else del[i] = true;
    }

    ll Sum = max(sum[0],sum[1]);
    if(Sum == 0LL){
        int pos = max_element(all(a)) - a.begin();
        del[pos] = false;
        Sum = a[pos];
    }else{
        rep(i,n) if(sum[i%2] < sum[(i+1)%2]){
            del[i] = true;
        }
    }

    vector<int> pos;
 
    int r = n-1;
    while(del[r]) pos.push_back(r--);

    int l = 0;
    while(del[l]) pos.push_back(0), l++;

    for(l+=2; l<=r; l+=2){
        pos.push_back(del[l] ? 2 : 1);
    }
 
    cout<<Sum<<endl<<pos.size()<<endl;
    for(int i : pos){
        cout<<i+1<<endl;
    }
    return 0;
}
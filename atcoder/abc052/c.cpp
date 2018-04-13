#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 

int main(void){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i = 2; i <= n; i++){
        int x = i;
        for(int d = 2; d<=x; d++){
            while(x%d == 0){
                mp[d]++;
                x /= d;
            }
        }
    }

    ll res = 1;
    for(auto itr : mp){
        res = res*(itr.second + 1)%mod;
    }
    cout<<res<<endl;

    return 0;
}

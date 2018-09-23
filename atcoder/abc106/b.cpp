#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

bool check(int x){
    if(x%2==0) return false;
    map<int,int> mp;
    int d = 3;
    while(x>1){
        if(x%d == 0){
            x /= d;
            mp[d]++;
        }else{
            d += 2;
        }
    }
    int cnt = 1;
    for(auto itr : mp){
        cnt *= itr.second+1;
    }
    return cnt == 8;
}

int main(void){
    int n;
    cin>>n;
    int cnt = 0;
    rep1(i,n){
        if(check(i)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

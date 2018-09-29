#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    map<int,int> mp[2];
    set<int> st;
    rep(i,n){
        int x;
        cin>>x;
        st.insert(x);
        mp[i&1][x]++;
    }
    using P = pair<int,int>;
    vector<P> vp[2];
    rep(i,2)for(auto itr : mp[i]){
        vp[i].push_back({itr.second, itr.first});
    }
    rep(i,2) sort(vp[i].begin(), vp[i].end(), greater<P>());
    if(vp[0][0].second != vp[1][0].second){
        cout<< n - vp[0][0].first - vp[1][0].first <<endl;
    }else{
        rep(i,2) vp[i].push_back({0, i});
        cout<< n - max(vp[0][1].first + vp[1][0].first, vp[0][0].first + vp[1][1].first)<<endl;;
    }
    return 0;
}

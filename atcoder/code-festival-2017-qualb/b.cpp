#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N,M;
    cin>>N;
    multiset<int> d;
    rep(i,N){
        int x;
        cin>>x;
        d.insert(x);
    }
    cin>>M;
    vector<int> t(M);
    rep(i,M)cin>>t[i];
    rep(i,M){
        auto itr = d.find(t[i]);
        if(itr == d.end()){
            cout<<"NO"<<endl;
            return 0;
        }
        d.erase(itr);
    }
    cout<<"YES"<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(){
    int N,A,res=1;
    map<int,int> mp;
    cin>>N;
    rep(i,N){
        cin>>A;
        mp[A]++;
        if(mp[A]>2 || A>=N || mp[0]>1)res=0;
    }
    rep(i,N/2)res=(res*2)%1000000007;
    cout<<res<<endl;
}

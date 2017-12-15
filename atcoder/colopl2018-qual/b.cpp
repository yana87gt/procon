#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,x;
    string s;
    cin>>n>>x>>s;
    int sum = 0;
    rep(i,n){
        int t;
        cin>>t;
        if(s[i]=='1' && t>x){
            sum += x;
        }else{
            sum += t;
        }
    }
    cout<<sum<<endl;

    return 0;
}

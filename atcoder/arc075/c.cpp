#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,sum=0,res=0;
    cin>>N;
    vector<int> s(N);
    rep(i,N)cin>>s[i],sum+=s[i];
    sort(s.begin(), s.end());
    if(sum%10)res=sum;
    else {
        rep(i,N){
            if((sum-s[i])%10){
                res=sum-s[i];
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

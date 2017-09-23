#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
ll M=1e9+7;

int main(void){
    int N,i;
    cin>>N;
    string s1,s2;
    cin>>s1>>s2;
    ll res=1;
    if(s1[0]==s2[0]){
        res=3;
        i=0;
    }else{
        res=6;
        i=1;
    }
    while(i<N-1){
        if(s1[i]==s2[i]){
            if(s1[i+1]==s2[i+1]){
                res=(res*2)%M;
                i+=1;
            }else{
                res=(res*2)%M;
                i+=2;
            }
        }else{
            if(s1[i+1]==s2[i+1]){
                i+=1;
            }else{
                res=(res*3)%M;
                i+=2;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

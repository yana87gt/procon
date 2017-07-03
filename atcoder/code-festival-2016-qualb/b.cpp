#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,A,B;
    string s;
    cin>>N>>A>>B>>s;
    rep(i,N){
        if(s[i]=='c' || A+B==0)cout<<"No"<<endl;
        else if(s[i]=='a'){
            if(A>0)A--;
            else B--;
            cout<<"Yes"<<endl;
        }else if(s[i]=='b' && B>0){
            B--;
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
    }

    return 0;
}

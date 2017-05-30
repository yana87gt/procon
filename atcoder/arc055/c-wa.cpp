#include <bits/stdc++.h>
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main(void){
    string s,A,B,C;
    int a,b,c,cnt=0;
    cin>>s;
    int N=s.length();
    rep1(a,N/2){
        A=s.substr(0,a);
        rep1(b,N-2*a){
            B=s.substr(a,b);
            if((N-2*a-b)%2==1)continue;
            c=(N-2*a-b)/2;
            C=s.substr(a+b,c);
            if(s.substr(a+b+c,a)==A && s.substr(a+b+c+a,c)==C)cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}

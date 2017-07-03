#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,len=1,cnt=0;
    string s;
    cin>>N>>s;
    s="O"+s+"O";
    rep(i,(int)s.size()){
        if(s[i]==s[i+1])len++;
        else {
            cnt+=len/2;
            if(len%2==0)N--;
            len=1;
        }
    }
    cout<<cnt<<endl<<N<<endl;
    return 0;
}

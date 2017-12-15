#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
int main(void){
    int A;
    string s;
    cin>>A>>s;
    rep(_,1010){
        int N = s.size();
        rep(i,N-1){
            while(s[i]+A<='z' && s[i+1]>'a'){
                s[i]+=A;
                s[i+1]--;
            }
        }

        if(N>1 && s[N-2]+A<='z' && s[N-1]=='a'){
            s[N-2] += A;
            s.erase(--s.end());
        }
    }
    cout<<s<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
bool used[10];
string word[10];
string SSS;
int N;

void backtrack(string s,int depth){
    if(depth==N){
        if(SSS.size()>s.size())SSS=s;
        else if(SSS.size()==s.size() && SSS>s)SSS=s;
        return;
    }
    rep(i,N){
        if(used[i])continue;
        used[i]=true;
        bool connect=false;
        for(int w=min(s.size(),word[i].size());;w--){
            if(s.substr(s.size()-w,w)==word[i].substr(0,w)){
                backtrack(s+word[i].substr(w,word[i].size()-w),depth+1);
                break;
            }
        }
        used[i]=false;
    }
}


int main(void){
    while(cin>>N,N){
        SSS="";
        rep(i,N){
            cin>>word[i];
            SSS+=word[i];
            used[i]=false;
        }
        backtrack("",0);
        cout<<SSS<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool solve(){
    int a,b;
    string s;
    cin>>a>>b>>s;
    if(s[a]=='-'){
        s[a] = '0';
        rep(i,a+b+1){
            if(!isdigit(s[i])){
                return false;
            }
        }
        return true;
    }
    return false;
}

int main(void){
    cout<<(solve()? "Yes" : "No")<<endl;
    return 0;
}

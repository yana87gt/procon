#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string so,se;
    cin>>so>>se;
    rep(i,se.size()){
        cout<<so[i]<<se[i];
    }
    if(se.size()<so.size())cout<<so.back();
    cout<<endl;
    return 0;
}

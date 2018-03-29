#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int h,w;
    cin>>h>>w;
    string t(w+2,'#');
    cout<<t<<endl;
    rep(i,h){
        string s;
        cin>>s;
        cout<<"#"+s+"#"<<endl;
    }
    cout<<t<<endl;
    return 0;
}

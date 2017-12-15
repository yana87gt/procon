#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    string s;
    cin>>a>>b>>s;
    if(s.size()>=a && s.size()<=b) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}

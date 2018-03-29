#include <bits/stdc++.h>
using namespace std;

int main(void){
    string a,b;
    cin>>a>>b;
    if(a==b) cout<<"EQUAL"<<endl;
    else if(a.size()!=b.size()){
        cout<<(a.size()>b.size() ? "GREATER" : "LESS")<<endl;
    }else{
        cout<<(a>b ? "GREATER" : "LESS")<<endl;
    }
    return 0;
}

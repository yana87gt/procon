#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,n;
    string s;
    cin>>a>>b>>n>>s;
    for(char c:s){
        if(c=='S'){
            a--;
        }
        if(c=='C'){
            b--;
        }
        if(c=='E'){
            if(a<b)b--;
            else a--;
        }
    }
    if(a<0) a = 0;
    if(b<0) b = 0;
    cout<<a<<endl<<b<<endl;
    return 0;
}

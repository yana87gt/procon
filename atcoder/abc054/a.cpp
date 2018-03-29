#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    if(a==1) a=14;
    if(b==1) b=14;
    if(a==b) cout<<"Draw"<<endl;
    else cout<<(a<b ? "Bob" : "Alice")<<endl;
    return 0;
}

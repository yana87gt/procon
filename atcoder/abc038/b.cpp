#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<( a==c || a==d || b==c || b==d ? "YES" : "NO")<<endl;
    return 0;
}

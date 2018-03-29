#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<(abs(a-b)%2==0 ? "Alice" : "Borys")<<endl;
    return 0;
}

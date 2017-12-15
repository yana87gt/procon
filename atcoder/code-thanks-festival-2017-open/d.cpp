#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}

int main(void){
    int n,m;
    cin>>n>>m;    
    cout<<m-gcd(n,m)<<endl;
    return 0;
}

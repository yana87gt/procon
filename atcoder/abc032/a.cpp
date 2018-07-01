#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}

int main(void){
    int a,b,n;
    cin>>a>>b>>n;
    int k = lcm(a,b);
    int res = k;
    for(int i=1; res<n; i++){
        res += k;
    }
    cout<<res<<endl;
    return 0;
}

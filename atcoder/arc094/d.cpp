#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    rep(i,n){
        long long a,b,c;
        cin>>a>>b;
        c = sqrt(a*b);
        if(c*(c+1) < a*b){
            cout<<2*c-1<<endl;
        }else if(a*b == c*c && a!=b){
            cout<<2*c-3<<endl;
        }else{
            cout<<2*c-2<<endl;
        }
    }
    return 0;
}

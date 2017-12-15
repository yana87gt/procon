#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,q;
    cin>>n>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(n>1)while(a!=b){
            if(a>b)swap(a,b);
            b = (b-1 + n-1)/n;
        }
        cout<<a<<endl;
    }
}

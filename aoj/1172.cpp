#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    int root = sqrt(n);
    for(int i=2;i<=root;++i)if(n%i==0)return false;
    return true;
}

int main(){
    int n,cnt;
    while(cin>>n,n){
        cnt=0;
        for(int i=n+1;i<=2*n;++i)if(prime(i))cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}

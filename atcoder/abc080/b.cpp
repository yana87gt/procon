#include <bits/stdc++.h>
using namespace std;

int f(int n){
    int res=0;
    while(n>0){
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(void){
    int n;
    cin>>n;
    cout<<(n%f(n)==0?"Yes":"No")<<endl;
    return 0;
}

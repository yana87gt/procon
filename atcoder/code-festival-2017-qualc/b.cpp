#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N;
    cin>>N;
    int odd = 1;
    rep(i,N){
        int a;
        cin>>a;
        if(a%2==0) odd*=2;
    }
    cout<<pow(3,N)-odd<<endl;
    return 0;
}

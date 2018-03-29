#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int a,b;
    cin>>b>>a;
    vector<string> c(100);
    rep(i,100){
        c[i] = string(100,(i<50 ? '.' : '#'));
    }
    rep(i,a-1){
        int x = (i%50)*2;
        int y = (i/50)*2;
        c[y][x] = '#';
    }
    rep(i,b-1){
        int x = (i%50)*2;
        int y = 99 - (i/50)*2;
        c[y][x] = '.';
    }
    cout<<"100 100"<<endl;
    for(string line : c){
        cout<<line<<endl;
    }
    return 0;
}

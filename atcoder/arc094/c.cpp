#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int v[3];
    rep(i,3)cin>>v[i];
    sort(v,v+3);
    int a = (v[2]-v[0])/2;
    int b = (v[2]-v[1])/2;
    int cnt = a+b;
    v[0] += a*2;
    v[1] += b*2;
    sort(v,v+3);
    if(v[1]!=v[2])cnt++;
    else if(v[0]!=v[1])cnt += 2;
    cout<<cnt<<endl;
    return 0;
}

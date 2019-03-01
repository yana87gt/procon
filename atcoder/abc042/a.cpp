#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int v[3];
    rep(i,3) cin >> v[i];
    sort(v,v+3);
    cout<<((v[0] == 5 && v[1] == 5 && v[2] == 7) ? "YES" : "NO")<<endl;
    return 0;
}

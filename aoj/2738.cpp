#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    int x = 0;
    bool ng = false;
    rep(i,n){
        string s;
        cin>>s;
        if(s == "A") x++;
        else x--;
        if(x < 0) ng = true;
    }
    cout<<((!ng && x == 0) ? "YES" : "NO")<<endl;
    return 0;
}

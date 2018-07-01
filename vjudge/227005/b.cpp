#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    while(cin>>n){
        vector<int> win(n);
        (n-1)*n;
        rep(i,n){
            cin>>win[i];
        }
        sort(all(win));
        bool ok = true;
        rep(i,n){
            if(win[i] != i) ok = false;
        }
        cout<<((ok) ? 1 : -1)<<endl;
    }
    return 0;
}

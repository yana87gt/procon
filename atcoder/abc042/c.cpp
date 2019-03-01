#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, k;
    cin >> n >> k;
    map<int,bool> ng;
    rep(i,k){
        int x;
        cin >> x;
        ng[x] = true;
    }
    while(true){
        string s = to_string(n);
        bool ok = true;
        rep(i,s.size()){
            if(ng[s[i]-'0']){
                ok = false;
            }
        }
        if(ok){
            cout << s << endl;
            break;
        }
        n++;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

void solve(string s){
    int depth = 0;
    rep(i,s.size()){
        int num = s[i]-'0';
        if (num > depth) {
            rep(j,num-depth){
                cout << "(";
            }
        } else if (num < depth) {
            rep(j,depth-num){
                cout << ")";
            }
        }
        depth = num;
        cout << num;
    }
    rep(j,depth){
        cout << ")";
    }
    cout << endl;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

bool check(string &s, string pas){
    int p = 0;
    int k = 3 - pas.size();
    rep(i,k){
        pas = "0" + pas;
    }
    for(char c : s){
        if (c == pas[p]) {
            p++;
        }
        if (p == 3) return true;
    }
    return false;
}

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,1000){
        if(check(s, to_string(i))){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

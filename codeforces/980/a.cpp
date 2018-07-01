#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

bool solve(string s){
    int p = count(all(s), 'o');
    int l = count(all(s), '-');
    if(min(p,l) == 0) return true;
    return l % p == 0;
}

int main(void){
    string s;
    cin>>s;
    s += s;
    cout<<((solve(s)) ? "YES" : "NO")<<endl;
    return 0;
}

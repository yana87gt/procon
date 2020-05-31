#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin >> s;
    map<char,int> map;
    for(char c : s){
        map[c]++;
    }
    cout << min(map['0'], map['1'])*2 << endl;
    return 0;
}

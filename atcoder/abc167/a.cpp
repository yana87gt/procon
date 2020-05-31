#include <bits/stdc++.h>
using namespace std;


int main(void){
    string s,t;
    cin >> s >> t;
    cout << ((t.substr(0, s.size()) == s) ? "Yes" : "No") << endl;
    return 0;
}

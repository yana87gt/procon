#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k;
    string s;
    cin >> k >> s;
    cout << ((int)s.size() <= k ? s : s.substr(0,k) + "...") << endl;
    return 0;
}

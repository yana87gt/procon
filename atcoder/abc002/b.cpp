#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    set<char> boin = {'a', 'i', 'u', 'e', 'o'};
    for (char c : s) {
        if (boin.find(c) == boin.end()) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()

int main(void){
    string s;
    cin >> s;
    cout << (int)s.size() - count(all(s),'-')*2 << endl;
    return 0;
}

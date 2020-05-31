#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    string s1(a,'0'+b), s2(b,'0'+a);
    cout << min(s1,s2) << endl;
    return 0;
}

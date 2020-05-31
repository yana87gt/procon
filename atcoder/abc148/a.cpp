#include <bits/stdc++.h>
using namespace std;

int main(void){
    set<int> s = {1,2,3};
    int a,b;
    cin >> a >> b;
    s.erase(a);
    s.erase(b);
    cout << *s.begin() << endl;

    return 0;
}

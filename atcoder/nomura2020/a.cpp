#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << max((h2*60+m2) - (h1*60+m1) - k, 0) << endl;
    return 0;
}

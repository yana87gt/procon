#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int cnt = 0;
    while (true) {
        if (a > b || c == 0) break;
        b -= a;
        c--;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

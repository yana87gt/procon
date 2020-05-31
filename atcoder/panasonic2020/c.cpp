#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long a,b,c;
    cin >> a >> b >> c;
    cout << ((4LL * a * b < (c-a-b) * (c-a-b) && (c-a-b >= 0)) ? "Yes" : "No") << endl;
    return 0;
}

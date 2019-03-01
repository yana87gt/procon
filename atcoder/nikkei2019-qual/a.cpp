#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a,b) << " " << max(a+b-n,0) << endl;
    return 0;
}

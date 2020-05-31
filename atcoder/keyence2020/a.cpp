#include <bits/stdc++.h>
using namespace std;

int main(void){
    double h,w,n;
    cin >> h >> w >> n;
    cout << (int)ceil(n/max(h,w)) << endl;
    return 0;
}

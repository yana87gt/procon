#include <bits/stdc++.h>
using namespace std;


int main(void){
    int x;
    cin >> x;
    cout << (x/500) * 1000 + (x%500)/5 * 5 << endl;
    return 0;
}

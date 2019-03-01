#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    cout << (
        n == 100 ? "Perfect" :
        n >= 90 ? "Great" :
        n >= 60 ? "Good" : "Bad") << endl;
    return 0;
}

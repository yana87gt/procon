#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> divisor;
    for (int i = 1; i <= sqrt(m); i++) {
        if (m % i == 0) {
            divisor.push_back(i);
            divisor.push_back(m/i);
        }
    }
    sort(divisor.begin(), divisor.end(), greater<int>());
    for (int g : divisor) {
        if (m/g >= n) {
            cout << g << endl;
            return 0;
        }
    }
    return 0;
}

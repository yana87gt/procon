#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int d_sum = 0;
    for (char c : s) {
        d_sum += c-'0';
    }
    cout<<((stoi(s)%d_sum == 0) ? "Yes" : "No")<<endl;
    return 0;
}

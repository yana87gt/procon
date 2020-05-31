#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    string book[] = {"pon", "pon", "hon", "bon", "hon", "hon", "pon", "hon", "pon", "hon"};
    cout << book[n%10] << endl;
    return 0;
}

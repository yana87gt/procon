#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int sum = 0;
    rep(i,12){
        string s;
        cin >> s;
        if (count(all(s), 'r') > 0) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}

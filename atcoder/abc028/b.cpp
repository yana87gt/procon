#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    string s;
    cin >> s;
    rep(i,6){
        char c = 'A'+i;
        cout << count(all(s), c) << (i < 5 ? " " : "\n");
    }
    return 0;
}

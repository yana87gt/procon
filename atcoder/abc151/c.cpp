#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n, m;
    cin >> n >> m;
    int wa_sum = 0;
    map<int, bool> ac;
    map<int, int> wa;
    int ac_count = 0;
    rep(i,m){
        int p;
        string s;
        cin >> p >> s;
        if (s == "WA" && !ac[p]) {
            wa[p]++;
        } else if (s == "AC" && !ac[p]) {
            ac[p] = true;
            ac_count++;
        }
    }
    for(auto itr : wa){
        int p = itr.first;
        if(ac[p]) wa_sum += wa[p];
    }
    cout << ac_count << " " << wa_sum << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    map<string,char> mp = {
        {"####.##.##.####",'0'},
        {".#.##..#..#.###",'1'},
        {"###..#####..###",'2'},
        {"###..####..####",'3'},
        {"#.##.####..#..#",'4'},
        {"####..###..####",'5'},
        {"####..####.####",'6'},
        {"###..#..#..#..#",'7'},
        {"####.#####.####",'8'},
        {"####.####..####",'9'}
    };
    int n;
    cin >> n;
    string res;
    string s[5];
    rep(i,5) cin >> s[i];
    rep(j,n){
        string num;
        rep(i,5){
            num += s[i].substr(4*j+1, 3);
        }
        res += mp[num];
    }
    cout << res << endl;
    return 0;
}

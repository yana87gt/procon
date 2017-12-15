#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int cnt[3] = {};
    for(char c : s) cnt[c-'a']++;
    sort(cnt,cnt+3);
    cout<<((cnt[2] - cnt[0] <= 1) ? "YES" : "NO")<<endl;
}

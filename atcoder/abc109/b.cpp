#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<string> s(n);
    map<string, int> mp;
    bool ng = false;
    rep(i,n){
        cin>>s[i];
        mp[s[i]]++;
        if (mp[s[i]] == 2) {
            ng = true;
        }
    }
    for (int i = 1; i < n; i++){
        if (s[i-1].back() != s[i].front()){
            ng = true;
        }
    }
    cout<<((!ng) ? "Yes" : "No")<<endl;
    return 0;
}

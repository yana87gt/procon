#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

void dfs(string &s, string sub,
    vector<string> &result, map<char,bool> &changed){
    if(s.size() == sub.size()){
        result.push_back(sub);
        return;
    }
    char c = s[sub.size()];
    if(!changed[c] && c!='z'){
        changed[c] = true;
        dfs(s,sub+char(c+1),result,changed);
        changed[c] = false;
    }
    if(changed[c-1] || c=='a'){
        dfs(s,sub+char(c),result,changed);
    }
}

int main(void){
    string s;
    while(cin>>s, s!="#"){
        vector<string> result;
        map<char,bool> changed;
        dfs(s,"",result,changed);
        sort(all(result));
        int m = result.size();
        cout<<m<<endl;
        rep(i,m){
            if(i<5 || m-5<=i) cout<<result[i]<<endl;
        }
    }
    return 0;
}

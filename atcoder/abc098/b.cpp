#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int n;
    string s;
    cin>>n>>s;
    int res = 0;
    rep1(i,n-1){
        set<char> xst,yst;
        string x = s.substr(0,i);
        string y = s.substr(i,n-i);
        xst.insert(all(x));
        yst.insert(all(y));
        vector<char> v;
        set_intersection(all(xst),all(yst),back_inserter(v));
        res = max(res,(int)v.size());
    }
    cout<<res<<endl;
    return 0;
}

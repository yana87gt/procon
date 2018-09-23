#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
typedef long long ll;

using P = pair<string,string>;

void rec(string &s,map<P,ll> &mp,int i,string s1,string s2){
    if(i == (int)s.size()){
        mp[P(s1,s2)]++;
        return;
    }
    rec(s,mp,i+1,s1+s[i],s2);
    rec(s,mp,i+1,s1,s2+s[i]);
}

int main(void){
    int n;
    string s;
    cin>>n>>s;
    string s1 = s.substr(0,n);
    string s2 = s.substr(n,n);
    reverse(all(s2));
    map<P,ll> mp1,mp2;
    rec(s1,mp1,0,"","");
    rec(s2,mp2,0,"","");
    ll res = 0;
    for(auto itr : mp1){
        P p = itr.first;
        res += mp1[p]*mp2[p];
    }
    cout<<res<<endl;
    return 0;
}

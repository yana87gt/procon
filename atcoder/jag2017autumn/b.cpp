#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

string s;
int i=0;
map<char, int> mp;

int read(){
    if(isalpha(s[i])) return mp[s[i++]];
    i++; // [
    int l = read();
    i++; // -
    int r = read();
    i++; // ]
    if(max(l,r)>0 && min(l,r)==0) return max(l,r)-1;
    return -10000;
}

int main(){
    cin>>s;
    string c;
    int d;
    while(cin>>c>>d) mp[c[0]]=d;
    cout<<((read()==0) ? "Yes" : "No")<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<string> split(string s,string d) {
    vector<string> elems;
    s += d;
    int r;
    for(int l=0; l<int(s.size()); l=r+d.size()){
        r = s.find(d,l);
        string item = s.substr(l,r-l);
        elems.push_back(item);
    }
    return elems;
}

string solve(vector<string> s1,vector<string> s2){
    if(s1.size() != s2.size()) return "DIFFERENT";
    int diff=0;
    rep(i,s1.size()) if(s1[i]!=s2[i]){
        if(i&1)diff++;
        else return "DIFFERENT";
    }
    if(diff==0) return "IDENTICAL";
    if(diff==1) return "CLOSE";
    return "DIFFERENT";
}

int main(void){
    while(true){
        string s1,s2;
        cin>>s1;
        if(s1==".") break;
        cin>>s2;
        cout<<solve(split(s1,"\""),split(s2,"\""))<<endl;
    }
    return 0;
}

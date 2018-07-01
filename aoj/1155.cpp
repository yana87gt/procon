#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

// <formula> ::= 0 | 1 | 2 | P | Q | R |
// -<formula> | (<formula>*<formula>) | (<formula>+<formula>)

int eval(string &s,int &i,map<char,int> &v){
    char c = s[i];
    i++;
    if(isdigit(c) || isalpha(c)) return v[c];
    if(c == '-') return 2-eval(s,i,v);
    int l = eval(s,i,v);
    char op = s[i];
    i++;
    int r = eval(s,i,v);
    i++;
    if(op == '*'){
        if(l*r == 0) return 0;
        if(l*r == 4) return 2;
        return 1;
    }
    if(op == '+'){
        if(l+r == 0) return 0;
        if(l== 2 || r == 2) return 2;
        return 1;
    }
    assert(false);
}

int main(void){
    string s;
    while(cin>>s, s!="."){
        int cnt = 0;
        map<char,int> v;
        rep(i,3) v['0'+i] = i;
        rep(p,3)rep(q,3)rep(r,3){
            int i = 0;
            v['P'] = p;
            v['Q'] = q;
            v['R'] = r;
            if(eval(s,i,v)==2) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

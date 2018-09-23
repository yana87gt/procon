#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)

// T := c | [opTT]
int eval(string &s, string &pas, int &i){
    if(isalpha(s[i])){
        int pos = s[i]-'a';
        i++;
        return pas[pos]-'0';
    }
    assert(s[i] == '[');
    i++; // [
    char op = s[i]; i++;
    int x = eval(s,pas,i);
    int y = eval(s,pas,i);
    i++; // ]
    if(op == '+') return x | y;
    if(op == '*') return x & y;
    if(op == '^') return x ^ y;
    assert(false);
}

int main(void){
    string s;
    while(cin>>s, s != "."){
        string p;
        cin>>p;
        int index = 0;
        int hash = eval(s,p,index);
        int cnt = 0;
        rep(i,10000){
            index = 0;
            string str = to_string(i);
            while((int)str.size() < 4){
                str = "0"+str;
            }
            if(eval(s,str,index) == hash) cnt++;
        }
        cout<<hash<<" "<<cnt<<endl;
    }

}
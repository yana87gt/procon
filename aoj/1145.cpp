#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

string s;
int K;

string mul(string str, int n){
    string res;
    rep(i,n){
        res += str;
        if((int)res.size() > K) break;
    }
    return res.substr(0,K+1);
}

// T := c..c | Nc | N(T) | TT
string read(int &i){
    if((int)s.size() == i || s[i] == ')') return "";

    string str;
    // c..c
    if(isalpha(s[i])){
        while(isalpha(s[i])){
            str += s[i];
            i++;
        }
    }else{
        int num = 0;
        while(isdigit(s[i])){
            num = num*10+(s[i]-'0');
            i++;
        }

        // Nc
        if(isalpha(s[i])){
            str = string(num,s[i]);
            i++;
        }
        // N(T)
        else{
            i++;
            str = mul(read(i),num);
            i++;        
        }
    }
    // TT
    return mul(str+read(i),1);
}


int main(void){
    while(cin>>s>>K, !(s=="0" && K==0)){
        int i = 0;
        string res = read(i);
        if((int)res.size() <= K){
            cout<<0<<endl;
        }else{
            cout<<res[K]<<endl;
        }
    }
    return 0;
}

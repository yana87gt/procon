#include <bits/stdc++.h>
using namespace std;

// T := (T)[V](T) | e

void waste(string &s,int &i){
    if(s[i] == ')') return; // e
    i++; // (
    waste(s,i);
    i++; // )
    i++; // [
    while(isdigit(s[i])) i++;
    i++; // ]
    i++; // (
    waste(s,i);
    i++; // )
}

string unite(string &s1,string &s2,int &a, int &b){
    if(s1[a] == ')'){
        waste(s2,b);
        return "";
    }
    if(s2[b] == ')'){
        waste(s1,a);
        return "";
    }

    string res;
    res += "(", a++, b++; // (
    res += unite(s1,s2,a,b);
    res += ")", a++, b++; // )
    res += "[", a++, b++; // [
    int n1 = 0, n2 = 0;
    while(isdigit(s1[a])){
        n1 = n1*10 + s1[a]-'0';
        a++;
    }
    while(isdigit(s2[b])){
        n2 = n2*10 + s2[b]-'0';
        b++;
    }
    res += to_string(n1+n2);
    res += "]", a++, b++; // ]
    res += "(", a++, b++; // (
    res += unite(s1,s2,a,b);
    res += ")", a++, b++; // )
    return res;
}

int main(void){
    string s1,s2;
    cin>>s1>>s2;
    int a = 0, b = 0;
    cout<<unite(s1,s2,a,b)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    cout<<((s[0]==s[1] && s[2]==s[3] && s[1]!=s[2]) ? "Yes" : "No")<<endl;
}
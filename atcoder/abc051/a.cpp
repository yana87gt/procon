#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    for(char &c : s){
        if(c==',') c = ' ';
    }
    cout<<s<<endl;
    return 0;
}

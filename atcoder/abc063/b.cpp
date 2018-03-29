#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    map<char,bool> used;
    for(char c:s){
        if(used[c]){
            cout<<"no"<<endl;
            return 0;
        }
        used[c] = true;
    }
    cout<<"yes"<<endl;
    return 0;
}

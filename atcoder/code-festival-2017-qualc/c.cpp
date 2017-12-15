#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int l=0,r=s.size()-1,cnt=0;
    while(l<r){
        if(s[l]==s[r])l++,r--;
        else if(s[l]=='x')l++,cnt++;
        else if(s[r]=='x')r--,cnt++;
        else{
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<cnt<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    cout<<((s.front() == s.back())^(s.size()&1) ? "First" : "Second")<<endl;
    return 0;
}

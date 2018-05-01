#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

int main(void){
    string s;
    cin>>s;
    sort(all(s));
    cout<<((s == "abc") ? "Yes" : "No")<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

int main(void){
    string s,t;
    cin>>s>>t;
    sort(all(s));
    sort(all(t));
    reverse(all(t));
    cout<<(s<t ? "Yes" : "No")<<endl;
    return 0;
}

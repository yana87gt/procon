#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

int main(void){
    string s1,s2;
    cin>>s1>>s2;
    reverse(all(s2));
    cout<<(s1==s2 ? "YES" : "NO")<<endl;
    return 0;
}

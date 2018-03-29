#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<((s1.back() == s2[0] && s2.back() == s3[0])?"YES":"NO")<<endl;
    return 0;
}

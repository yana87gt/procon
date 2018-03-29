#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

int main(void){
    int a,b,cnt=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        string s1 = to_string(i);
        string s2 = s1;
        reverse(all(s2));
        if(s1==s2)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

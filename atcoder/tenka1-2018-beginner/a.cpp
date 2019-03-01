#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()

int main(void){
    string s;
    cin>>s;
    if(s.size() == 2) {
        cout<<s<<endl;
    }else{
        reverse(all(s));
        cout<<s<<endl;
    }
    return 0;
}

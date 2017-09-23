#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

int main(void){
    string s,r;
    cin>>r;
    s=r;
    reverse(all(r));
    cout<<((s==r)?"Yes":"No")<<endl;
    return 0;
}

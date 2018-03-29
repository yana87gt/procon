#include <bits/stdc++.h>
using namespace std;

int main(void){
    string a,b;
    cin>>a>>b;
    int n = stoi(a+b);
    int s = sqrt(n);
    cout<<((s*s==n) ? "Yes" : "No")<<endl;
    return 0;
}

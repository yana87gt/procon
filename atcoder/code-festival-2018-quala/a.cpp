#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,s;
    cin>>a>>b>>c>>s;
    int sum = a+b+c;
    cout<<((sum<=s && s<=sum+3) ? "Yes" : "No")<<endl;
    return 0;
}

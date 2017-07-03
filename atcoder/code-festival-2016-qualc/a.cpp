#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int c=s.find("C"),f=s.rfind("F");
    cout<<(c<f && c>=0 && f>=0 ? "Yes":"No")<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d,n;
    cin>>d>>n;
    cout<<(int)pow(100,d)*(n==100 ? 101 : n)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int X;
    cin>>X;
    int i=sqrt(X*2);
    if(i*(i+1)/2<X)i++;
    cout<<i<<endl;
    return 0;
}

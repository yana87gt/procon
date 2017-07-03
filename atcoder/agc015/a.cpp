#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long N,A,B;
    cin>>N>>A>>B;
    if(A==B)cout<<1<<endl;
    else if(A>B || N==1)cout<<0<<endl;
    else cout<<(B-A)*(N-2)+1<<endl;
    return 0;
}

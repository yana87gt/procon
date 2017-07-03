#include <iostream>
using namespace std;
int main(){
    long long N,M;
    cin>>N>>M;
    if(M-2*N>=0)cout<<(M-2*N)/4 + N<<endl;
    else cout<<M/2<<endl;
}

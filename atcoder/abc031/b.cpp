#include <iostream>
using namespace std;

int main(void){
    int L,H,N,A;
    cin>>L>>H>>N;
    while(N--){
        cin >> A;
        if(A<L)cout<<L-A<<endl;
        else if(A>H)cout<<-1<<endl;
        else cout<<0<<endl;
    }

    return 0;
}

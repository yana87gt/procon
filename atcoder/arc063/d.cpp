#include <iostream>
using namespace std;
int main(void){
    int N,T,A,minA,maxD=0,cnt=0;
    cin>>N>>T>>minA;
    while(--N){
        cin>>A;
        if(A<minA)minA=A;
        else if(A-minA==maxD)cnt++;
        else if(A-minA>maxD){
            cnt=1;
            maxD=A-minA;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

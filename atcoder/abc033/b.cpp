#include <iostream>
using namespace std;

int main(void){
    int i,N,P,maxP=0,sum=0;
    string S,maxS;
    cin >> N;
    for(i=0;i<N;i++){
        cin>>S>>P;
        sum+=P;
        if(maxP<P){
            maxS=S;
            maxP=P;
        }
    }
    cout<<(maxP>sum/2 ? maxS : "atcoder")<<endl;

    return 0;
}

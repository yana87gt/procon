#include<iostream>
using namespace std;

int main(void){
    int N,A,B;

    cin>>N;
    cin>>A;
    cin>>B;

    /*A==B*/
    if(A==B){
        if(N%(A+1))cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
        return 0;
    }

    /*A>B*/
    if(A>B){
        cout<<"Takahashi"<<endl;
        return 0;
    }

    /*A<B*/
    if(N<=A)cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
    return 0;
}

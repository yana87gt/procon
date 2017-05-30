#include <iostream>
using namespace std;

int main(void){
    int left,right,N;

    cin>>N;
    cin>>right;
    cout<<right;

    while(N>2){
        left=right;
        cin>>right;
        if(left<right)cout<<" "<<left;
        else cout<<" "<<right;
        N--;
    }
    cout<<" "<<right<<endl;

    return 0;
}

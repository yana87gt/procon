#include <iostream>
using namespace std;

int main(void){
    char x;

    cin>>x;
    if(x=='O' || x=='P' || x=='K' || x=='L')
    cout<<"Right"<<endl;
    else cout<<"Left"<<endl;

    return 0;
}

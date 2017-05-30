#include <iostream>
using namespace std;

int main(void){
    char L,S;

    cin>>L>>S;
    cout <<(L-'A'+'a'==S ? "Yes" : "No") << endl;

    return 0;
}

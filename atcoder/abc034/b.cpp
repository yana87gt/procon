#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    cout<<(n%2==0 ? n-1 : n+1)<<endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int A,B,ans;

    cin>>A>>B;
    if((A>0&&B>0)||(A<0&&B<0)) ans = B-A;
    else ans = B-A-1;
    cout<<ans<<endl;

    return 0;
}

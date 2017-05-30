#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B;
    cin>>A>>B;
    cout<<(B%A==0 ? B/A : B/A + 1)<<endl;
}

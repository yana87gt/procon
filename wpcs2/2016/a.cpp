#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,x,y,z;
    int a[3];
    cin>>N;
    while(N--){
        cin>>x>>y>>z;
        a[0]=fabs(x-y);
        a[1]=fabs(y-z);
        a[2]=fabs(z-x);
        cout<<min({a[0],a[1],a[2]})<<endl;
    }

    return 0;
}

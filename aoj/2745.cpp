#include <bits/stdc++.h>
using namespace std;

int main(void){
    int R0,W0,C,R;
    while(cin>>R0>>W0>>C>>R, R0|W0|C|R)
    {
        cout<<max(0,(C*W0-R0+R-1)/R)<<endl;
    }
    return 0;
}

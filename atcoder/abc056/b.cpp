#include <bits/stdc++.h>
using namespace std;
int main(void){
    int w,a,b;
    cin>>w>>a>>b;
    if((b<=a+w && a<=b)||(a<=b+w && b<=a)){
        cout<<0<<endl;
    }else{
        cout<<min(abs(b+w-a),abs(a+w-b))<<endl;
    }
    return 0;
}

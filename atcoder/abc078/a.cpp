#include <bits/stdc++.h>
using namespace std;

int main(void){
    char x,y;
    cin>>x>>y;
    if(x<y) cout<<"<"<<endl;
    else if(x>y) cout<<">"<<endl;
    else if(x==y) cout<<"="<<endl;
    return 0;
}

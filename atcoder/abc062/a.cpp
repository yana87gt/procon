#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x,y;
    cin>>x>>y;
    int g[]={0,1,3,1,2,1,2,1,1,2,1,2,1};
    cout<<(g[x]==g[y] ? "Yes" : "No")<<endl;
    return 0;
}

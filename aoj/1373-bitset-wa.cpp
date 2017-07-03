#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000001
bitset<MAX> bs;

bool insert(int x){
    //  [0]
    if(bs[0])return false;
    if(!bs[x]) {
        bs[x]=true;
        return true;
    }
    bool fail=true;
    for(int i=1;i<=x;i++){
        if(!bs[i]){
            fail=false;
            break;
        }
    }
    if(fail)return false;
    for(bool carry=true;carry;x--){
        carry=bs[x];
        bs[x]=!bs[x];
    }
    return true;
}

int main(void){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        if(insert(x))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

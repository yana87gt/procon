#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lc[90];
ll lucas(int n){
    if(lc[n]) return lc[n];
    if(n==0) return 2;
    if(n==1) return 1;
    return lc[n] = lucas(n-1)+lucas(n-2);
}

int main(void){
    int n;
    cin>>n;
    cout<<lucas(n)<<endl;
    return 0;
}

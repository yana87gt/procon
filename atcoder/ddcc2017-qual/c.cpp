#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int N,C;
    cin>>N>>C;
    vector<int> L(N); 
    rep(i,N)cin>>L[i];
    sort(all(L));

    int cnt=0,l=0,r=N-1;
    while(l<r){
        if(L[l]+L[r]+1<=C){
            cnt++;
            l++,r--;
        }else{
            cnt++;
            r--;
        }
    }
    if(l==r)cnt++;
    cout<<cnt<<endl;
    return 0;
}

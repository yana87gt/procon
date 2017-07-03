#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int N,M,x,cnt=0;
    cin>>N>>M;
    map<int,bool> a;
    rep(i,M){
        cin>>x;
        a[x]=true;
    }
    queue<int> qu;
    rep(i,N)qu.push(i);
    while(qu.size()>1){
        int l=qu.front(); qu.pop();
        int r=qu.front(); qu.pop();
        if(!a[l] && !a[r])cnt++;

        if(!a[r])qu.push(r);
        else qu.push(l);
    }
    cout<<cnt<<endl;
    return 0;
}

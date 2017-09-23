#include <bits/stdc++.h>
using namespace std;

int solve(int n,int s,int f){
    if(s==f) return -1;
    if(f-s==1){
        if(1<s && f<n) return -1;
        else return 1;
    }
    int res=0;
    if(s>1) res++,s++;
    if(f<n) res++,f--;
    return res+(f-s)/3+(f-s)%3;
}

int main(){
    int n,s,f;
    cin>>n>>s>>f;
    if(s>f) swap(s,f);
    cout<<solve(n,s,f)<<endl;
}

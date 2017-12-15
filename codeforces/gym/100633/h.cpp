#include <bits/stdc++.h>
using namespace std;

int solve(int n,int s,int f){
    int res=0;
    if(1<s) res++,s++;
    if(f<n) res++,f--;
    if(s>f) return -1;
    return res+(f-s)/3+(f-s)%3;
}

int main(){
    int n,s,f;
    cin>>n>>s>>f;
    if(s>f) swap(s,f);
    cout<<solve(n,s,f)<<endl;
}
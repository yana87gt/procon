#include <bits/stdc++.h>
using namespace std;
int N;

string solve(string a,string b){
    int A = a.size();
    int B = b.size();
    int r = 0;
    while(!(r<=N && (N-r)%A==0)) r += B;
    string res;
    while(res.size() < N-r) res += a;
    while(res.size() < N)   res += b;
    return res;
}

int main(){
    string s,t;
    cin>>N>>s>>t;
    cout<<min(solve(s,t),solve(t,s))<<endl;
}

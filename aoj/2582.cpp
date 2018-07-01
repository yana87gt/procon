#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    while(cin>>n, n){
        bool on = 0, l = 0, r = 0;
        int cnt = 0;
        rep(i,n){
            string s;
            cin>>s;
            if(s[0]=='l') l ^= 1;
            if(s[0]=='r') r ^= 1;
            if(l==r && on^l){
                on ^= 1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

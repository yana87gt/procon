#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

// s1がs2の部分文字列
bool substring(string s1,string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1>n2) return false;
    int j=0;
    rep(i,n2){
        if(s1[j]==s2[i]){
            j++;
        }
    }
    return j==n1;
}

int main(void){
    string s;
    cin>>s;
    cout<<((substring(s,"AKIHABARA")&&substring("KIHBR",s)) ? "YES" : "NO")<<endl;
}

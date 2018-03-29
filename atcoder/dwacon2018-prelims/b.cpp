#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int c2=0,c5=0,res=0;
    for(char c : s){
        if(c=='2') c2++;
        else c5++;
        if(c2<c5){
            cout<<-1<<endl;
            return 0;
        }
        res = max(res,c2-c5);
    }
    cout<<(c2==c5 ? res : -1)<<endl;
    return 0;
}

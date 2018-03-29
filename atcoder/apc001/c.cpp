#include <bits/stdc++.h>
using namespace std;

string ask(int x){
    cout<<x<<endl;
    string res;
    cin>>res;
    if(res == "Vacant") exit(0);
    return res;
}

int main(void){
    int n;
    cin>>n;
    int l=0,r=n-1,m=n/2;
    string ls=ask(l), ms=ask(m), rs=ask(r);
    while(true){
        if(((m-l)%2==0 && ms==ls) || ((m-l)%2==1 && ms!=ls)){
            l = m;
            ls = ms;
        }else{
            r = m;
            rs = ms;
        }
        m = (l+r)/2;
        ms = ask(m);
    }
    return 0;
}

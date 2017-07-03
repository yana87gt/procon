#include <bits/stdc++.h>
using namespace std;
struct Fraction{int numer,denom;};
Fraction add(Fraction f1,Fraction f2){
    return Fraction{f1.numer*f2.denom+f2.numer*f1.denom , f1.denom*f2.denom};
}

int p,q,a,n,cnt;

void solve(Fraction f,Fraction f1,int depth){
    Fraction next;
    while(1){
        next = add(f,f1);
        if(q*next.numer <= p*next.denom)break;
        f1.denom++;
    }
    if(next.denom>a)return;
    if(q*next.numer == p*next.denom){
        cnt++;
        f1.denom++;
    }
    while(1){
        Fraction tmp = {n-depth,f1.denom};
        tmp = add(f,tmp);
        if(q*tmp.numer < p*tmp.denom)return;
        next = add(f,f1);
        if(next.denom>a)return;
        solve(next,f1,depth+1);
        f1.denom++;
    }
}

int main(void){
    while(cin>>p>>q>>a>>n,p|q|a|n){
        cnt=0;
        solve(Fraction{0,1},Fraction{1,1},0);
        cout<<cnt<<endl;
    }
    return 0;
}

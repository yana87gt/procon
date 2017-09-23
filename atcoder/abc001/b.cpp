#include <bits/stdc++.h>
using namespace std;

int main(void){
    int m;
    cin>>m;
    if(m<100){
        cout<<"00"<<endl;
    }else if(m<=5000){
        if(m<1000)cout<<"0";
        cout<<m/100<<endl;
    }else if(m<=30000){
        cout<<m/1000+50<<endl;
    }else if(m<=70000){
        cout<<(m/1000-30)/5+80<<endl;
    }else{
        cout<<89<<endl;
    }
    return 0;
}

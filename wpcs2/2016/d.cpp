#include <bits/stdc++.h>
using namespace std;

int main(void){
    int L;
    while(cin>>L,L){
        char i,a='a';
        while(L--){
            cin>>i;
            if(i=='+')a++;
            else if(i=='-')a--;
            else cout<<a;
            if(a=='a'-1)a='z';
            if(a=='z'+1)a='a';
        }
        cout<<endl;
    }

    return 0;
}

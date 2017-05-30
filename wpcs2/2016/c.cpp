#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d;
    string s[8]={"N","NW","W","SW","S","SE","E","NE"};
    while(cin>>d,d!=-1)cout<<s[d/45]<<endl;
    return 0;
}

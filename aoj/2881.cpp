#include <bits/stdc++.h>
using namespace std;

int main(void){
    string g;
    int y,m,d;
    while(cin>>g, g!="#"){
        cin>>y>>m>>d;
        if(!(y <= 30 || (y == 31 and m <= 4))){
            g = "?";
            y -= 30;
        }
        cout<<g<<" "<<y<<" "<<m<<" "<<d<<endl;
    }
}

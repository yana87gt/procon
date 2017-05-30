#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,Y;
    cin>>N;
    while(N--){
        cin>>Y;
        Y-=1892;
        if(Y<=0 || Y%4>0)cout<<-1<<endl;
        else cout<<Y/4<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*1年1月1日から数えて何日目かを返す関数*/
int calc(int y,int m,int d){
    return (y-1)*195+(y-1)/3*5 + (m-1)*20-(y%3==0 ? 0 : (m-1)/2) + d;
}

int main(void){
    int n,Y,M,D;
    int Millennium = calc(1000,1,1);
    cin>>n;
    while(n--){
        cin>>Y>>M>>D;
        cout<<Millennium-calc(Y,M,D)<<endl;
    }

    return 0;
}

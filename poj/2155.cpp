#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{
    double x,y;
    bool operator<(const Point& right)const{
        return (x==right.x ? y<right.y : x<right.x);
    }
};

int main(void){
    int X,N,T;
    cin>>N>>X>>T;
    while(X--){
        rep(_,T){
            char CQ;
            int x,y,x1,y1,x2,y2;
            cin>>CQ;
            if(CQ=='Q'){
                cin>>x>>y;
            

            }else{
                cin>>x1>>y1>>x2>>y2;
            

            }
        }
    }



    return 0;
}

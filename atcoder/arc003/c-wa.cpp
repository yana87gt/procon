#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct Point{double x,y;};
bool comp(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}

int main(void){
    int N,M;
    cin>>N>>M;
    string c[502]={};
    rep(y,N) cin>>s[y];

    //時間と経路最低明るさを比べると、
    //明るさを優先させるべき
    

    rep(y,N){
        string s;
        cin>>s;
        rep(x,M){
            if(s[x]=='#') c[y][x]=0;
            else if(s[x]=='s') c[y][x]=-1;
            else if(s[x]=='g') c[y][x]=-2;
            else c[y][x]=s[x]-'0';
        }
    }



    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(void){
    int N,M;
    while(cin>>M>>N){
        int y = 0, x = 0, dir = 0;
        bool ok = true;
        rep(i,N){
            string s;
            int d;
            cin>>s>>d;
            if(s == "MOVE"){
                x += dx[dir]*d;
                y += dy[dir]*d;
            }else{
                dir = (dir+(d==0 ? 3 : 1))%4;
            }
            if(x<0 || x>M || y<0 || y>M){
                ok = false;
            }
        }
        if(ok)cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}

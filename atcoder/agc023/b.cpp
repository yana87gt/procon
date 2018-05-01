#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int n;
vector<string> s;

int solve(int Y,int X){
    int W = 2*n-max(Y,X);
    vector<string> s1;
    rep(i,W){
        s1.push_back(s[Y+i].substr(X,W));
    }

    int imos[W][W+1] = {};
    rep(y,W){
        rep(x,W){
            imos[y][x+1] = imos[y][x] + (s1[y][x] != s1[x][y]);
        }
    }

    int res = 0;
    rep(i,2*n){
        int sy = Y+i, sx = X+i;
        if(sx>=n || sy>=n){
            break;
        }
        bool ok = true;
        rep(j,n){
            if(imos[j][j+1] != imos[j][n+1]){
                ok = false;
            }
        }
        if(ok) res++;
    }
    return res;
}


int main(void){
    cin>>n;
    s.resize(n);
    rep(i,n){
        cin>>s[i];
        s[i] += s[i];
    }
    rep(i,n){
        s.push_back(s[i]);
    }
    int res = 0;

    rep(i,n){
        res += solve(0,i);
    }
    rep1(i,n-1){
        res += solve(i,0);
    }
    cout<<res<<endl;
    return 0;
}

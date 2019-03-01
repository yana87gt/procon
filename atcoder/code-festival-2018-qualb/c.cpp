#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;

bool is_in(int y, int x){
    return y>=0 && x>=0 && y<n && x<n;
}

int main(void){
    cin>>n;
    int mod[5] = {1,3,0,2,4};
    vector<string> s(n);
    rep(y,n){
        string line(n,'.');
        rep(x,n){
            if(y%5 == mod[x%5]) {
                line[x] = 'X';
            }
        }
        s[y] = line;
    }
    rep(k,n){
        int yy[] = {k,k,0,n-1};
        int xx[] = {0,n-1,k,k};
        rep(j,4){
            int y = yy[j];
            int x = xx[j];
            bool ok = false;
            rep(i,4){
                if(!is_in(y+dy[i],x+dx[i])) continue;
                if(s[y+dy[i]][x+dx[i]]=='X') ok = true;
            }
            if(!ok) s[y][x] = 'X';
        }
    }
    rep(y,n) cout<<s[y]<<endl;
    return 0;
}

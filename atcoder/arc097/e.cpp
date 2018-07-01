#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9

using P = pair<int,char>;

// x-1とxをswap
void swap(int x, vector<P> &v, map<char,vector<int>> &pos){
    char c1 = v[x-1].second;
    char c2 = v[x].second;
    int a1 = v[x-1].first;
    int a2 = v[x].first;
    swap(v[x-1], v[x]);
    pos[c1][a1] = x;
    pos[c2][a2] = x-1;
}

int solve(int n, vector<P> v, map<char,vector<int>> pos){
    int w=0,b=0,cnt=0;
    pos['W'].push_back(INF);
    pos['B'].push_back(INF);
    rep(i,n*2-1){
        P dw = {pos['W'][w]-i, 'W'};
        P db = {pos['B'][b]-i, 'B'};
        P close = min(dw,db);
        char c = close.second;
        assert(w<=n && b<=n);
        assert(close.first >= 0);
        cnt += close.first;
        for(int x = i+close.first; x > i; x--){
            swap(x,v,pos);
        }
        if(c == 'W') w++;
        else b++;
    }
    cerr<<__func__<<cnt<<endl;
    return cnt;
}

// int right_move(int n, vector<P> v, map<char,vector<int>> pos){
//     int w=n-1,b=n-1,cnt=0;
//     for(int i = 2*n-1; i>0; i--){
//         P dw = {i-pos['W'][w], 'W'};
//         P db = {i-pos['B'][b], 'B'};
//         P close = min(dw,db);
//         if(close.first < 0){
//             close = max(dw,db);
//         }
//         char c = close.second;
//         // if(close.first < 0){
//         //     debug(i);
//         //     debug(w);
//         //     debug(b);
//         // }
//         // if(w<=0 && b<=0){
//         //     debug(w);
//         //     debug(b);
//         //     printf("\ncnt = %d\n",cnt);
//         //     printf("i = %d: c,dist = %c,%d \n",i,close.second,close.first);
//         // }
//         cnt += close.first;
//         for(int x = i-close.first+1; x <= i; x++){
//             swap(x,v,pos);
//         }
//         if(c == 'W') w--;
//         else b--;
//     }
//     // cerr<<__func__<<cnt<<endl;
//     return cnt;
// }


// int solve(int n, vector<P> v, map<char,vector<int>> pos){
//     int w=n-1,b=n-1,cnt=0;
//     for(int i = 2*n-1; i>0; i--){
//         P dw = {i-pos['W'][w], 'W'};
//         P db = {i-pos['B'][b], 'B'};
//         P close = min(dw,db);
//         if(close.first < 0){
//             close = max(dw,db);
//         }
//         char c = close.second;
//         // if(close.first < 0){
//         //     debug(i);
//         //     debug(w);
//         //     debug(b);
//         // }
//         // if(w<=0 && b<=0){
//         //     debug(w);
//         //     debug(b);
//         //     printf("\ncnt = %d\n",cnt);
//         //     printf("i = %d: c,dist = %c,%d \n",i,close.second,close.first);
//         // }
//         cnt += close.first;
//         for(int x = i-close.first+1; x <= i; x++){
//             swap(x,v,pos);
//         }
//         if(c == 'W') w--;
//         else b--;
//     }
//     // cerr<<__func__<<cnt<<endl;
//     return cnt;
// }

int main(void){
    int n;
    cin>>n;
    vector<P> v(n*2),rv(n*2);
    map<char,vector<int>> pos,rpos;
    pos['W'].resize(n);
    pos['B'].resize(n);
    rpos['W'].resize(n);
    rpos['B'].resize(n);
    rep(i,n*2){
        char c;
        int a;
        cin>>c>>a;
        a--;
        v[i] = {a,c};
        rv[n*2-1-i] = {n-1-a,c};
        pos[c][a] = i;
        rpos[c][n-1-a] = n*2-1-i;

    }
    int res1 = solve(n,v,pos);
    int res2 = solve(n,rv,rpos);
    cout<<min(res1,res2)<<endl;
    return 0;
}

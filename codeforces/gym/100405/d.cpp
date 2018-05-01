#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;




ll solve(int N, int H, vector<int> ls){
    int W = ls[0];
    bool b[7][7] = {};
    rep(i,H){
        rep(j, ls[i]){
            b[i][j] = true;
        }
    }

    vector<int> col(W);
    rep(i,W){
        int cnt = 0;
        while(b[cnt][i])cnt++;
        col[i] = cnt;
    }
    

    return 0;
}

int main(void){
    string line;
    while(getline(cin, line)){
        string str_n;
        getline(cin, str_n);
        int n = stoi(str_n);
        vector<int> ls;
        for(char c : line){
            if(isdigit(c)){
                ls.push_back(c-'0');
            }
        }
        cout<<solve(n, ls.size(), ls)<<endl;
    }
    return 0;
}

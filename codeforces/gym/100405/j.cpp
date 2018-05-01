#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 1e9

vector<vector<int>> g;
vector<bool> isBall;

// T := () | (B) | (TT)
int read(string &s, int &num, int &index){
    assert(s[index] == '(');
    index++; // (
    int x = num;
    num++;
    if(s[index] == 'B'){
        isBall[x] = true;
        index++; // B
    }else if(s[index] == ')'){
    }else if(s[index] == '('){
        g[x].push_back(read(s,num,index));
        g[x].push_back(read(s,num,index));
    }
    index++; // )
    return x;
}


int dfs(int x, int ball){
    if(g[x].size() == 0){
        if(ball >= 2) return INF;
        if(isBall[x] && ball==0) return 1;
        return 0;
    }

    int half[2] = {ball/2, (ball+1)/2};
    int res[2] = {};
    rep(i,2) {
        rep(child,2){
            res[i] += dfs(g[x][child], half[child]);
        }
        if(ball%2==0) return res[0];
        swap(half[0], half[1]);
    }
    return min(res[0], res[1]);
}


int main(void){
    string s;
    while(cin>>s){
        int N = count(all(s),'(');
        g.clear();
        g.resize(N);
        isBall.clear();
        isBall.resize(N);
        int num = 0, index = 0;
        read(s, num, index);
        int res = dfs(0,count(all(s),'B'));
        if(res>=INF) cout<<"impossible"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}

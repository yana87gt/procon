#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<int> g[100001];
int color[100001];//-1:パス, 0:無色, 1:有色
int N;

bool check_path(int prev,int v){
    if(v==N)return true;
    bool isPath=false;
    for(int to:g[v])if(to!=prev){
        isPath |= check_path(v,to);
    }
    if(isPath)color[v]=-1;
    return isPath;
}

bool paint(deque<int> &qu){
    if(qu.empty()) return false;
    while(color[qu.front()]>0){
        qu.pop_front();
        if(qu.empty()) return false;
    }
    int v = qu.front();
    qu.pop_front();
    color[v] = 1;
    for(int to:g[v]){
        if(color[to]==-1)qu.push_front(to);
        if(color[to]==0)qu.push_back(to);
    }
    return true;
}

int main(void){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    check_path(-1,1);
    color[1] = 0;
    
    deque<int> fennec,snuke;    
    fennec.push_front(1);
    snuke.push_front(N);
    while(true){
        if(!paint(fennec)){
            cout<<"Snuke"<<endl;
            break;
        }
        if(!paint(snuke)){
            cout<<"Fennec"<<endl;
            break;
        }
    }

    return 0;
}

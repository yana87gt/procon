#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
struct Edge{int from,to,cost;};
int F,N,M,W,S,E,T;
vector<Edge> e;
vector<int> d;

/* ベルマンフォード法 */
bool solve(){
    rep1(v,N)d[v]=0;
    rep1(v,N)rep(i,2*M+W){
        if(d[e[i].to]>d[e[i].from]+e[i].cost){
            d[e[i].to]=d[e[i].from]+e[i].cost;
            if(v==N)return true;
        }
    }
    return false;
}

int main(void){
    cin>>F;
    while(F--){
        cin>>N>>M>>W;
        d.resize(N+1);
        e.clear();
        rep(i,M){
            cin>>S>>E>>T;
            e.push_back({S,E,T});
            e.push_back({E,S,T});
        }
        rep(i,W){
            cin>>S>>E>>T;
            e.push_back({S,E,-T});
        }
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}

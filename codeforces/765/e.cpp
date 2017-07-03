#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(x) cout<<#x<<": "<<x<<endl

vector<int> g[200005];

int pre[200005];
typedef pair<int, int> P;
int n;
//first=weight ,second=id
//直径の2つの端点を求めつつ、prevを記録
P dfs1(int v) {
    P r = {0, v};
    for(int to:g[v])if(to!=pre[v]){
        P t = dfs1(to);
        pre[to]=v;
        t.first++;
        if(r.first<t.first){
            r=t;
        }
    }
    return r;
}

//distance between leaf and v
int dfs2(int prev,int v){
    if(g[v].size()==1)return 1;
    set<int> st;
    for(int to:g[v])if(to!=prev)
        st.insert(dfs2(v,to));
    if(st.size()==1 && *(st.begin())>0)
        return *(st.begin())+1;
    else return -1;
}

int solve() {
    P U = dfs1(1);
    int u=U.second;
    rep1(i,n)pre[i]=0;
    P V = dfs1(u);
    int v = V.second;
    int D = V.first;
    //printf("(u,v,D) = (%d,%d,%d)\n",u,v,D );
    //直径が奇数
    if(D&1){
        int O1=v;
        rep(i,D/2) O1=pre[O1];
        int O2=pre[O1];
        int r1=dfs2(O2,O1);
        int r2=dfs2(O1,O2);
        // debug(r1);
        // debug(r2);
        if(r1==r2 && r1!=-1) return D;
    }else{
        int O=v;
        rep(i,D/2)O=pre[O];
        debug(O);
        set<int> st;
        for(int to:g[O]){
            st.insert(dfs2(O,to));
        }
        if(st.size()<=2){
            D=0;
            for(auto x:st){
                D+=x;
            }

            while(D%2==0 && D>0){
                D/=2;
            }
            return D;
        }
    }
    return -1;
}


int main(void){
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<solve()<<endl;
    return 0;
}

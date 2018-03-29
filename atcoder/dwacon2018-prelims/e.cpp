#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 1e9
#define MAXN 2010
int n,q;

vector<int> g[MAXN];
bool centroid[MAXN]; // 重心になったことがある
int subSize[MAXN];   // ある頂点をrootとしたときの部分木のサイズ

int getSubSize(int v, int p) {
    int& sum = subSize[v];
    sum = 1;
    for(int ch : g[v]){
        if (ch == p || centroid[ch]) continue;
        sum += getSubSize(ch, v);
    }
    return sum;
}

// t: 分解された木のサイズ
// secondが重心
pair<int,int> getCentroid(int v, int p, int t) {
    pair<int,int> ret(INF, -1);
    // m: 頂点vを根にした時の部分木の中で最大のサイズ
    int sum = 1, m = 0;
    for(int ch : g[v]){
        if (ch == p || centroid[ch]) continue;
        m = max(m, subSize[ch]);
        sum += subSize[ch];
        ret = min(ret, getCentroid(ch, v, t));
    }
    m = max(m, t-sum);
    ret = min(ret, pair<int,int>(m, v));
    return ret;
}

void eraseEdge(int v,int p){
    rep(i,g[p].size())if(g[p][i]==v){
        g[p].erase(g[p].begin()+i);
    }
}

int main(void){
    cin>>n>>q;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int v = 1, res;
    while(true){
        getSubSize(v,-1);
        int c = getCentroid(v,-1,subSize[v]).second;
        centroid[c] = true;

        if(g[c].size() == 0){
            cout<<"! "<<c<<endl<<flush;
            break;
        }

        if(g[c].size()==1){
            cout<<"? "<<c<<" "<<g[c][0]<<endl<<flush;
            cin>>res;
            cout<<"! "<<res<<endl<<flush;
            break;
        }

        vector<pair<int,int>> vp;
        for(int ch : g[c]){
            vp.push_back({getSubSize(ch,c),ch});
        }
        sort(all(vp));
        reverse(all(vp));
        int a = vp[0].second, b = vp[1].second;
        cout<<"? "<<a<<" "<<b<<endl<<flush;
        cin>>res;
        if(res == 0){
            eraseEdge(a,c);
            eraseEdge(b,c);
            v = c;
        }else{
            eraseEdge(c,res);
            v = res;
        }
    }
    return 0;
}

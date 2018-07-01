#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int N;
    while(cin>>N){
        vector<pair<int,int>> g(N+1);
        rep1(i,N){
            int l,r;
            cin>>l>>r;
            g[i] = {l,r};
        }
        stack<pair<int,int>> st; // index, depth
        st.push({1,1});
        int res = N;
        while(st.size()){
            pair<int,int> top = st.top(); st.pop();
            int v = top.first;
            int depth = top.second;
            if(g[v].first == 0 || g[v].second == 0){
                res = min(res, depth);
            }else{
                st.push({g[v].first,  depth+1});
                st.push({g[v].second, depth+1});
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

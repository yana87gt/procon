#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int N,M;

int dfs(int i, int cnt,
    bitset<500> cur, vector<bitset<500>> &bs){
    if(N == i) return cur.count() == 0 ? cnt : 0;
    return max(dfs(i+1,cnt,cur,bs), dfs(i+1,cnt+1,cur^bs[i],bs));
}

int main(void){
    while(cin>>N>>M, N|M){
        vector<bitset<500>> bs(N);
        rep(i,N) cin>>bs[i];
        if(N <= 23){
            cout<<dfs(0,0,bitset<500>(""),bs)<<endl;
        }else{
            vector<int> cur(1<<M),nxt(1<<M);
            rep(i,N){
                int bit = bs[i].to_ullong();
                nxt[bit] = max(cur[bit],cur[0]+1);
                rep(mask,1<<M)if(cur[mask]){
                    nxt[bit^mask] = max(nxt[bit^mask],cur[mask]+1);
                }
                cur = nxt;
            }
            cout<<cur[0]<<endl;
        }
    }
    return 0;
}

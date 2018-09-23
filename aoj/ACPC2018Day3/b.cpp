#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)

int main(){
    int n,Q;
    cin>>n>>Q;
    vector<int> a(n+2), pre(n+2), nxt(n+2), q(Q);
    rep1(i,n){
        cin>>a[i];
    }
    rep(i,Q) cin>>q[i];
    a[0] = 0;
    a[n+1] = n+1;
    rep1(i,n){
        pre[a[i]] = a[i-1];
        nxt[a[i]] = a[i+1];
    }
    nxt[0] = a[1];
    pre[n+1] = a[n];

    rep(j,Q){
        int p = q[j];
        int v1 = nxt[0];
        int v2 = pre[p];
        int v3 = nxt[p];
        int v4 = pre[n+1];

        if(v3 == n+1){
            nxt[0] = p;
            pre[p] = 0;
        }else{
            nxt[0] = v3;
            pre[v3] = 0;

            nxt[v4] = p;
            pre[p] = v4;
        }

        if(v2 == 0){
            pre[n+1] = p;
            nxt[p] = n+1;
        }else{
            nxt[p] = v1;
            pre[v1] = p;

            nxt[v2] = n+1;
            pre[n+1] = v2;
        }

    }

    int cur = nxt[0];
    rep(i,n){
        cout<<cur<<(i < n-1 ? " " : "\n");
        cur = nxt[cur];
        i++;
    }
    return 0;
}
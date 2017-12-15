#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

vector<int> a[2];
int N;

// x以下を動かす
bool check(int x){
    rep(i,2){
        rep(l,N) if(a[i][l] > x){
            int r = l+1;
            while(r < N){
                if(a[i][r] == a[i][l]){
                    l = r;
                    break;
                }
                if(a[i][r] > x) return false;
                r++;
            }
            if(r == N) return false;
        }
    }
    return true;
}

int main(void){
    cin>>N;
    a[0].resize(N);
    a[1].resize(N);
    rep(i,N) cin>>a[0][i];
    rep(i,N) cin>>a[1][i];
    int l = -1, r = 1e9+5;
    // l以下のみを動かすのは無理、r以下を動かすのならばいける
    while(l+1 < r){
        int m = (l+r)/2;
        if(check(m)) r = m;
        else l = m;
    }
    cout<<r<<endl;

    return 0;
}

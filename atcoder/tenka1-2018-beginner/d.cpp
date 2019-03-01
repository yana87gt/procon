#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n;
    cin>>n;
    if(n==1){
        printf("Yes\n2\n1 1\n1 1\n");
        return 0;
    }
    int k = -1;
    rep1(i,n){
        if(i*(i-1)/2 == n) {
            k = i;
        }
    }
    if(k == -1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl<<k<<endl;
    int g[1000][1000] = {};
    int cnt = 1;
    rep1(i,k)rep1(j,k)if(i!=j && g[i][j]==0){
        g[i][j] = g[j][i] = cnt;
        cnt++;
    }
    assert(cnt == n+1);
    rep1(i,k){
        cout<<k-1;
        rep1(j,k)if(i!=j){
            cout<<" "<<g[i][j];
        }
        cout<<endl;
    }

    return 0;
}

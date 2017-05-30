#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int a[200][200]={};
int x[200]={};
int y[200]={};
int H,W,N;

int solve2(){

    rep(i,H)rep(j,W)
}

int solve3(){

}

int main(void){

    cin>>H>>W>>N;

    rep(i,H){
        rep(j,W){
            cin>>a[i][j];
            y[i]+=a[i][j];
            x[j]+=a[i][j];
        }
    }



    return 0;
}

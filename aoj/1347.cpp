#include <bits/stdc++.h>
using namespace std;

int main(void){
    bool a[1001]={};
    int N,m,cnt=0;
    cin>>N>>m;
    while(m--){
        int c,d;
        cin>>c>>d;//dはcより先に行く店
        for(int i=c;i<d;++i)a[i]=true;//dからcに戻る時の道
    }
    for(int i=0;i<=N;++i)if(a[i])cnt++;//戻った道のりを数える
    cout<<N+1+cnt*2<<endl;//N+1＝入り口から出口までの距離、count*2＝引き返し

    return 0;
}

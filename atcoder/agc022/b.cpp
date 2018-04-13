#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int N;
    cin>>N;
    if(N==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }

    vector<int> res;
    rep(i,30000/12){
        for(int j : {2,4,3,9,8,10,6,12}){
            res.push_back(i*12 + j);
        }
    }

    if(N&1) res[N-1] = 30000;
    rep(i,N){
        cout<<res[i]<<(i==N-1 ? "\n" : " ");
    }
    return 0;
}

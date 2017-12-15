#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int K,N;
    cin>>K>>N;
    vector<int> a;
    if(K%2==0){
        a = vector<int>(N,K);
        a[0] = K/2;
    }else{
        a = vector<int>(N,(K+1)/2);
        rep(i,N/2){
            if(a.back()==1) a.pop_back();
            else{
                a.back()--;
                while(int(a.size())<N)a.push_back(K);
            }
        }
    }
    rep(i,int(a.size())-1){
        cout<<a[i]<<" ";
    }
    cout<<a.back()<<endl;
    return 0;
}

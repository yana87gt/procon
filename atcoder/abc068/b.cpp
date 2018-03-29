#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> res = {1,2,4,8,16,32,64,128};
    rep(i,res.size()){
        if(res[i]<=n && n<res[i+1]){
            cout<<res[i]<<endl;
            break;
        }
    }
    return 0;
}

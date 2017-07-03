#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define N 20

int solve(vector<bool> bit,bool left){
    int cnt=0;
    if(left){
        rep1(j,2){
            bit[j] = !bit[j];
        }
        cnt++;
    }
    
    rep1(i,N-1)if(bit[i]){
        rep(j,2){
            bit[i+j] = !bit[i+j];
        }
        cnt++;
    }
    return cnt;
}

int main(void){
    vector<bool> bit(N+2);
    rep1(i,N){
        int input;
        cin>>input;
        bit[i]=input;
    }
    cout<<min(solve(bit,true),solve(bit,false))<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    cin>>n;
    vector<int> pos(n);
    rep(i,n){
        int a;
        cin>>a;
        a--;
        pos[a] = i;
    }
    int pre_pos = -1;
    int max_inc_seq = 0;
    int inc_seq = 0;
    rep(i,n){
        if(pre_pos < pos[i]){
            inc_seq++;
            max_inc_seq = max(max_inc_seq,inc_seq);
        }else{
            inc_seq = 1;
        }
        pre_pos = pos[i];
    }
    cout<< n - max_inc_seq <<endl;
    return 0;
}

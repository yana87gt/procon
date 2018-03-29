#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n;
    deque<int> deq;
    cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        if(i%2==0){
            deq.push_front(a);
        }else{
            deq.push_back(a);
        }
    }
    rep(i,n){
        cout<<(n%2==1 ? deq[i] : deq[n-1-i])<<(i<n-1 ? " " : "\n");
    }
    return 0;
}

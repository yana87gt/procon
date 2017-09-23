#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    set<int> paper;
    int N;
    cin>>N;
    rep(i,N){
        int x;
        cin>>x;
        if(paper.find(x)==paper.end()){
            paper.insert(x);
        }else{
            paper.erase(x);
        }
    }
    cout<<paper.size()<<endl;
    return 0;
}

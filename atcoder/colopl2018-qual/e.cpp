#include <bits/stdc++.h>
using namespace std;
#define M 2000
vector<pair<int,int>> res;

void pb(int x,int y){
    res.push_back({x,y});
}

int main(void){
    int k;
    cin>>k;
    pb(M,0);
    pb(M-2,0);
    pb(M-2,1);
    int x=M-2,y=1;
    k -= 2;
    for(int t=0; 4*t+1<=k; k-=4*t+1, t++){
        pb(-x,y);
        pb(-x,-y);
        x -= 2;
        pb(x,-y);
        y += 2;
        pb(x,y);
    }
    
    pb(1,y);
    y -= (k/2)*2+1;
    pb(1,y);
    pb(0,y);
    pb(0,M);

    if(k&1){
        pb(M-1,M);
        pb(M-1,-M);
        pb(M,-M);
    }else{
        pb(M,M);
    }

    cout<<res.size()<<endl;
    for(auto p : res){
        printf("%d %d\n",p.first,p.second);
    }
    return 0;
}

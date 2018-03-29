#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int a,b,c,d,e,f,resW=0,resS=0;
    cin>>a>>b>>c>>d>>e>>f;
    bitset<3010> bsW(1),bsS(1);
    rep(i,3001){
        bsW |= bsW<<(100*a*i) | bsW<<(100*b*i);
        bsS |= bsS<<(c*i) | bsS<<(d*i);
    }
    double rate=0;
    rep(w,f+1)rep(s,f)if(bsW[w] && bsS[s]){
        if(w+s<=f && w>0 && e*w >= s*100 && rate <= 1.0*s/w){
            rate = 1.0*s/w;
            resW = w;
            resS = s;
        }
    }
    cout<<resS+resW<<" "<<resS<<endl;
    return 0;
}

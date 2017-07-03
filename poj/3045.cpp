#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
struct Cow{
    int w,s;
    bool operator<(const Cow& right)const{
        return (w+s<right.w+right.s);
    }
};

int main(void){
    int N,maxR=INT_MIN,sumW=0;
    scanf("%d",&N);
    Cow c[N];
    rep(i,N)scanf("%d%d",&c[i].w,&c[i].s);
    sort(c,c+N);
    rep(i,N){
        maxR=max(maxR,sumW-c[i].s);
        sumW+=c[i].w;
    }
    printf("%d\n",maxR);
    return 0;
}
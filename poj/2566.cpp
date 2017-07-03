#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n,k,v,t;
    while(scanf("%d%d",&n,&k),n|k){
        vector< pair<int,int> > s(n+1);
        rep1(i,n){
            scanf("%d",&v);
            s[i]={s[i-1].first+v,i};
        }
        sort(s.begin(),s.end());
        while(k--){
            int t,left=0,resl,resr,nearest=INT_MAX;
            scanf("%d",&t);
            rep1(right,n){
                while(1){
                    int secsum = s[right].first-s[left].first;
                    if(abs(secsum-t)<abs(nearest-t)){
                        resl=min(s[right].second,s[left].second)+1;
                        resr=max(s[right].second,s[left].second);
                        nearest=secsum;
                    }
                    if(secsum>t && left+1<right)left++;
                    else break;
                }
            }
            printf("%d %d %d\n",nearest,resl,resr);
        }
    }
    return 0;
}

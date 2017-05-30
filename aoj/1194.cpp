#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main(void){
    int r,n,left,right,height;
    double minh;
    map<int,int> s;

    while(cin>>r>>n,r|n){
        /* 初期化 */
        rep(i,21)s[i]=s[-i]=0;
        minh = 21;
        while(n--){
            cin>>left>>right>>height;
            for(int i=left;i<right;++i){
                if(s[i]<height)s[i]=height;
            }
        }

        rep(i,r)minh = min(minh,min(s[i],s[-i-1])-sqrt(r*r-i*i));
        printf("%.4f\n",minh+r);
    }

    return 0;
}

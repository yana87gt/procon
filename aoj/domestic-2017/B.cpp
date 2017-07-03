#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
    int T,D,L;
    while(cin>>T>>D>>L,T|D|L){
        vector<int> imos(T+D);
        rep(i,T){
            int x;
            cin>>x;
            if(x>=L)imos[i]++,imos[i+D]--;
        }
        int res=0;
        rep(i,T-1){
            imos[i+1]+=imos[i];
            if(imos[i]>0)res++;
        }
        cout<<res<<endl;
    }
    return 0;
}

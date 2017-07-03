#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
pair<int,int> a[5000];

int main(void){
    int T,n;
    cin>>T;
    rep(t,T){
        cin>>n;
        rep(i,n)cin>>a[i].first>>a[i].second;
        sort(a,a+n);
        int wood=n,cnt=0;
        while(wood){
            cnt++;
            int value=0;
            rep(i,n){
                if(a[i].second>=value){
                    value=a[i].second;
                    wood--;
                    a[i].second=-1;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

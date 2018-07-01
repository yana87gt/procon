#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        rep(i,n) cin>>a[i];
        int res = n;
        int sum = 0;
        int l = 0;
        rep(r,n){
            sum += a[r];
            while(l < r && sum-a[l] >= s){
                sum -= a[l];
                l++;
            }
            if(sum >= s){
                res = min(res, r-l+1);
            }
        }
        if(accumulate(a.begin(),a.end(),0) < s){
            cout<<0<<endl;
        }else{
            cout<<res<<endl;
        }
    }
    return 0;
}

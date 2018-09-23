#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(),(a).end()

int main(void){
    int n;
    while(cin>>n, n){
        vector<int> a(n);
        rep(i,n){
            cin>>a[i];
        }
        int ave = accumulate(all(a), 0)/n;
        int cnt = 0;
        rep(i,n){
            if(a[i] <= ave) cnt++;
        }
        cout<<cnt<<endl;
    }  
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        int n;
        cin>>n;
        vector<int> v[2];
        rep(i,n){
            int x;
            cin>>x;
            v[i%2].push_back(x);
        }
        sort(all(v[0]));
        sort(all(v[1]));
        vector<int> res(n);
        rep(i,n){
            res[i] = v[i%2][i/2];
        }
        bool ok = true;
        rep(i,n-1){
            if(res[i]>res[i+1]){
                ok = false;
                cout<<i<<endl;
                break;
            }
        }
        if(ok)cout<<"OK"<<endl;
    }
    return 0;
}

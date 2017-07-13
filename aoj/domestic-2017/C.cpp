#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()

int main(void){
    int N,M;
    while(cin>>N>>M,N|M){
        vector<pair<int,int>> a(N+1),b(N+1); //max,min
        rep1(i,N) a[i].second=b[i].second=i;
        rep(i,M){
            int s,k,c;
            cin>>s>>k;
            rep(j,k){
                cin>>c;
                if(k==1) b[c].first += s;
                a[c].first += s;
            }
        }
        sort(all(a));
        sort(all(b));
        if(a[N].second == b[1].second){
            cout<<max(a[N].first-b[2].first,a[N-1].first-b[1].first)+1<<endl;
        }else{
            cout<<a[N].first-b[1].first+1<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define INF 1e9

int N,M;

int solve(vector<int> b, vector<int> goal){
    int cnt=0;
    rep(l,N)if(b[l]!=goal[l]){
        int r=l;
        do{
            if(r==N-1)return 1000;
            r++;
        }while(b[l]==b[r]);

        while(l<r){
            swap(b[r],b[r-1]);
            r--;
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    cin>>N>>M;
    vector<int> b(N),goal1(N),goal2(N);
    rep(i,N) cin>>b[i];
    int index=0;
    rep(i,M) {
        int p;
        cin>>p;
        rep(j,p){
            goal1[index] = (i%2==0);
            goal2[index] = (i%2!=0);
            index++;
        }
    }
    cout<<min(solve(b,goal1),solve(b,goal2))<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

long long C[60][60]={};
long long com(int n, int r){
    if(C[n][r]!=0) return C[n][r];
    else if(n==r || r==0) return C[n][r]=1;
    else if(r==1 || r==n-1) return C[n][r]=n;
    else return  C[n][r] = C[n][n-r] = com(n-1,r-1) + com(n-1,r);
}

int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> v(n);
    rep(i,n){
        cin>>v[i];
    }
    sort(all(v));
    reverse(all(v));

    ll sum = 0;
    rep(i,a) sum += v[i];

    int l = 0, r = n;
    rep(i,n){
        if(v[i] == v[a-1]) {
            l = i;
            break;
        }
    }

    rep(i,n)if(a<=i){
        if(v[i] != v[a-1]) {
            r = i;
            break;
        }
    }
    
    printf("%.10f\n",(double)sum/a);
    ll csum = 0;
    
    for(int k = a; k <= r && k <= b; k++){
        csum += com(r-l,k-l);
        if(l>0)break;
    }
    cout<<csum<<endl;
    return 0;
}

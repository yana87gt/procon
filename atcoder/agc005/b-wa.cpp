#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

vector<int> a;
int main(void){
    int N;
    ll sum=0;
    cin>>N;
    a.resize(N+1);
    rep(i,N)scanf("%d ",&a[i]);
    rep(i,N){
        int left,right;
        for(left=i;left>=0 && a[i]<=a[left];left--);
        for(right=i;right<N && a[i]<=a[right];right++);
        sum+=(ll)a[i]*(i-left)*(right-i);
    }
    cout<<sum<<endl;
    return 0;
}

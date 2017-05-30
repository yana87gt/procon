#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
struct man{int n,order;};
bool comp(man a,man b){return a.n<b.n;}

int main(void){
    int N;
    int A,B;
    cin>>N;

    int *a = new int[N+1];
    rep1(i,N){
        cin>>a[i];
    }

    man *m = new man[N+1];
    rep1(i,N){
        cin>>m[i].n;
        m[i].order=i;
    }

    cout<<"result"<<endl;

    return 0;
}

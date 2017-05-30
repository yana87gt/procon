#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;++i)
struct Seat{int a,n,o;};
bool comp_a(Seat x,Seat y){return x.a<y.a;}
bool comp_n(Seat x,Seat y){return x.n<y.n;}

int main()
{
    int i,N;
    cin >> N;
    Seat *s = new Seat[N+1];
    rep(i,N){
        cin >> s[i].a;
        s[i].n = i;
    }
    sort(s,s+N,comp_a);

    int order=0;
    s[0].o = 0;
    for(i=1;i<N;i++)
    {
        if(s[i].a==s[i-1].a){
            s[i].o = order;
        }else {
            s[i].o = ++order;
        }
    }
    sort(s,s+N,comp_n);
    rep(i,N){
        cout << s[i].o << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

int solve(){
    int N,L;
    cin>>N>>L;
    vector<int> a(L);
    int rem = N;
    rep(i,L){
        cin>>a[i];
        rem -= a[i];
    }

    vector<bool> ceiler(N+1);
    rep1(i,N){
        double per = 100.0/N*i;
        ceiler[i] = (floor(per+0.5) == round(per+0.5));
    }
    
    vector<int> next_ceiler(N+1);
    next_ceiler[N] = INF;
    rep(i,N){
        int k = N-i;
        next_ceiler[k-1] = next_ceiler[k];
        if(ceiler[k]){
            next_ceiler[k-1] = k;
        }

    }

    using P = pair<int,int>; // next_ceiler[a[i]]-a[i], index
    priority_queue<P, vector<P> ,greater<P>> pq;

    rep(i,L){
        pq.push({next_ceiler[a[i]]-a[i], i});
    }
    rep(i,rem){
        pq.push({next_ceiler[0], a.size()});
        a.push_back(0);
    }

    if(next_ceiler[0] == INF){
        a[0] += rem;
    }else{
        while(rem > 0){
            P pr = pq.top(); pq.pop();
            int diff = pr.first;
            int index = pr.second;
            a[index] += diff;
            rem -= diff;
            if(rem < 0) a[index] += rem;
            pq.push({next_ceiler[a[index]]-a[index], index});
        }
    }

    int M = a.size();
    int res = 0;
    rep(i,M){
        res += (int)round(100.0*a[i]/N);
    }
    return res;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        cout<<solve()<<endl;
    }
    return 0;
}

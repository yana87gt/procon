#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

template <typename T>
class SegmentTree{
  public:
    int n;
    T element;
    vector<T> dat;
    function<T(T,T)> operate;

    SegmentTree(){}
    SegmentTree(int n_,T element_,function<T(T,T)> operate_){
        element = element_;
        operate = operate_;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(n*2,element);
    }

    void update(int k,T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = operate(dat[k*2+1],dat[k*2+2]);
        }
    }

    T query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l) return element;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return operate(vl,vr);
    }

    T query(int a,int b) { return query(a,b,0,0,n);}
};



ll solve(vector<ll> x,vector<ll> v,ll n, ll c){
    SegmentTree<ll> st(n,0LL, [](ll a,ll b){return max(a,b);});
    ll sumV = 0;
    rep(i,n){
        sumV += v[i];
        st.update(i, sumV-x[i]*2);
    }

    reverse(all(x));
    reverse(all(v));
    sumV = 0;
    ll res = 0;
    rep(i,n){
        sumV += v[i];
        ll dist = c-x[i];
        res = max((sumV-dist) + max(st.query(0,n-i-1),0LL), res);
    }

    return res;
}

int main(void){
    ll n,c;
    cin>>n>>c;
    vector<ll> x(n),v(n);
    rep(i,n){
        cin>>x[i]>>v[i];
    }
    vector<ll> rx = x, rv = v;
    ll res1 = solve(x,v,n,c);
    reverse(all(rx));
    reverse(all(rv));
    rep(i,n){
        rx[i] = c-rx[i];
    }
    ll res2 = solve(rx,rv,n,c);
    cout<<max(res1,res2)<<endl;
    return 0;
}

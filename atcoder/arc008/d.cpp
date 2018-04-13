#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
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

using P = pair<double,double>;

P op(P f,P g){
    return P{f.first*g.first, f.second*g.first+g.second};
}

int main(void){
    ll n,m;
    cin>>n>>m;
    vector<ll> p(m);
    vector<double> a(m),b(m);
    map<ll,int> zip;
    rep(i,m){
        cin>>p[i]>>a[i]>>b[i];
        zip[p[i]];
    }
    int index = 0;
    for(auto itr : zip){
        zip[itr.first] = index++;
    }

    n = zip.size();
    SegmentTree<P> st(n,P{1,0},op);

    double mn = 1, mx = 1;
    rep(i,m){
        st.update(zip[p[i]], P{a[i],b[i]});
        P q = st.query(0,n);
        double res = q.first + q.second;
        mn = min(mn,res);
        mx = max(mx,res);
    }
    printf("%.10f\n%.10f\n",mn,mx);
    return 0;
}

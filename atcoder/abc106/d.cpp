#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(),(a).end()

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

    T query(int a,int b) { return query(a,b,0,0,n); }

    T get(int k){ return query(k,k+1); }
};

struct P{
    int l,r,id;
    bool q;
};

bool operator<(const P a, const P b) {
    if(a.r != b.r) return a.r < b.r;
    if(a.q != b.q) return b.q;
    return a.l < b.l;
}

int main(void){
    int n,m,q;
    cin>>n>>m>>q;
    vector<P> segs;
    rep(i,m){
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r+1,0,false});
    }
    rep(i,q){
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r+1,i,true});
    }
    vector<int> res(q);
    sort(all(segs));
    SegmentTree<int> stree(n+1, 0, [](int a,int b){return a+b;});

    for(P seg : segs){
        if(seg.q){
            res[seg.id] = stree.query(seg.l, seg.r);
        }else{
            stree.update(seg.l, stree.get(seg.l)+1);
        }
    }
    for(int x : res){
        cout<<x<<endl;
    }
    return 0;
}

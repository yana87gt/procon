///
/// for vscode snippet
/// prefix: lib-SegmentTree
///

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


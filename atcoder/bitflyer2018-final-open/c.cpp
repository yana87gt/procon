#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define INF 1e9

template <typename T>
class SegmentTree{
  public:
    int n;
    T elm;
    vector<T> dat;
    function<T(T,T)> op;

    SegmentTree(){}
    SegmentTree(int n_,T elm_,function<T(T,T)> op_){
        elm = elm_;
        op = op_;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(n*2,elm);
    }

    void update(int k,T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = op(dat[k*2+1],dat[k*2+2]);
        }
    }

    T query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l) return elm;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a,b,k*2+1,l,(l+r)/2);
        T vr = query(a,b,k*2+2,(l+r)/2,r);
        return op(vl,vr);
    }

    T query(int a,int b) { return query(a,b,0,0,n);}
};



int main(void){
    string s;
    cin>>s;
    int n = s.size();
    SegmentTree<int> st(n,INF,[](int a,int b){ return min(a,b);});

    vector<int> h(n);
    map<int,vector<int>> rh;
    int y = 0;
    rep(i,n){
        if(s[i] == '('){
            y++;
        }else{
            y--;
            rh[y].push_back(i);
        }
        st.update(i,y);
        h[i] = y;
    }

    long long res = 0;
    rep(i,n)if(s[i] == '('){
        y = h[i]-1;
        int pos = lb(rh[y],i);
        int l = pos;
        int r = rh[y].size();
        if(l==r) continue;
        while(l + 1 < r){
            int m = (l+r)/2;
            if(st.query(i,rh[y][m]) >= y){
                l = m;
            }else{
                r = m;
            }
        }
        res += l - pos + 1;
    }
    cout<<res<<endl;
    return 0;
}

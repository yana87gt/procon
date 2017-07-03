#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(s) s.begin(),s.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin();
typedef long long ll;
typedef pair<ll,int> Sub;

void make_sub(int l,int r,int cnt,ll sum,vector<ll> &elm,vector<Sub> &sub){
    if(l==r){
        if(cnt>0)sub.push_back(Sub(sum,cnt));
    }else {
        make_sub(l+1,r,cnt+1,sum+elm[l],elm,sub);
        make_sub(l+1,r,cnt,sum,elm,sub);
    }
}

Sub _abs(Sub x){ return Sub(llabs(x.first),x.second); }
Sub _add(Sub x,Sub y){ return Sub(_abs(Sub(x.first+y.first,x.second+y.second))); };
void _min(Sub &res,Sub x){ res = min(res,x); }
bool _equal(Sub x,Sub y){ return x.first == y.first; }

int main(void){
    int N;
    while(cin>>N,N){
        vector<ll> v(N);
        vector<Sub> subA,subB;
        rep(i,N)cin>>v[i];
        make_sub(0,N/2,0,0,v,subA);
        make_sub(N/2,N,0,0,v,subB);
        sort(all(subA));
        subA.erase(unique(all(subA),_equal),subA.end());
        int A = subA.size(), B = subB.size();
        int a = lb(subA,Sub(0,0));
        Sub res = _abs(Sub(v[0],1));
        if(a<A)_min(res,_abs(subA[a]));
        if(a>0)_min(res,_abs(subA[a-1]));

        rep(b,B){
            _min(res,_abs(subB[b]));
            a = lb(subA,Sub(-subB[b].first,0));
            if(a<A)_min(res,_add(subA[a],subB[b]));
            if(a>0)_min(res,_add(subA[a-1],subB[b]));
        }
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}

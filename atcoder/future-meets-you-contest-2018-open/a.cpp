#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
#define uniq(a) a.erase(unique(all(a)),a.end())
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
const int INF = 1e9;

int get_sign(int x){
    return x > 0 ? +1 : -1;
}

int main(void){
    int n,K;
    cin>>n>>K;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        a[i] -= i+1;
    }
    rep(loop,K){
        int abs_max_idx = 0;
        int abs_max = abs(a[0]);
        rep(i,n){
            if( abs_max < abs(a[i])){
                abs_max = abs(a[i]);
                abs_max_idx = i;
            }
        }


        int mid_sign = get_sign(a[abs_max_idx]);

        int l = abs_max_idx-1;
        for(; l >= 0; l--){
            if(mid_sign != get_sign(a[l])){
                l++;
                break;
            }
        }

        int r = abs_max_idx+1;
        for(; r < n; r++){
            if(mid_sign != get_sign(a[r])){
                r--;
                break;
            }
        }
        int height = abs(a[l]);
        for(int i = l; i <= r; i++){
            if (height > abs(a[i])){
                height = abs(a[i]);
            }
        }

        int ll = 0, rr = r-l, sum = 0;
        for(int i = 0; i <= rr; i++){
            sum += a[i];
        }
        int add = 2e9;
        int min_rr = 0;
        if (!(l<=ll&&ll<=r)||(l<=rr&&rr<=r)){
            add = abs(sum + (r-l+1)*height*mid_sign);
            min_rr = rr;
        }
        while(rr+1 < n){
            sum -= a[ll];
            ll++;
            rr++;
            sum += a[rr];
            if (!(l<=ll&&ll<=r)||(l<=rr&&rr<=r)){
                if (add > abs(sum + (r-l+1)*height*mid_sign)){
                    add = abs(sum + (r-l+1)*height*mid_sign);
                    min_rr = rr;
                }
            }
        }
        if(mid_sign == +1){
            printf("%d %d %d %d %d\n",l,r,ll,rr,height);
        }else{
            printf("%d %d %d %d %d\n",ll,rr,l,r,height);
        }
        for(int i = l; i<=r; i++){
            a[i] -= height*mid_sign;
        }
        for(int i = ll; i<=rr; i++){
            a[i] += height*mid_sign;
        }
    }
    return 0;
}

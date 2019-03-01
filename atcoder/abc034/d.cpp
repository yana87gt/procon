#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

class SaltWater{
  public:
    double w,p,s;
    static double target;
    SaltWater(): w(0),p(0),s(0) {}
    ~SaltWater() {}
    SaltWater(double w_, double p_): w(w_), p(p_), s(w_*p_) {}

    bool operator<(const SaltWater &right) const {
        return w*(p-target) < right.w*(right.p-target);
    }
    SaltWater operator+(const SaltWater right) {
        return SaltWater(w+right.w, (s+right.s)/(w+right.w));
    }
};
double SaltWater::target = 0;

int n,k;
vector<SaltWater> v;

bool check(double P){
    SaltWater::target = P;
    sort(all(v));
    reverse(all(v));
    SaltWater sum;
    rep(i,k){
        sum = sum + v[i];
    }
    return sum.p >= P;
}

int main(void){
    cin >> n >> k;
    v.resize(n);
    rep(i,n){
        double w,p;
        cin >> w >> p;
        v[i] = SaltWater(w, p/100.0);
    }

    double ok = 0, ng = 1;
    rep(loop,50){
        double mid = (ok+ng)/2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    printf("%.10f\n", ok*100.0);
    return 0;
}

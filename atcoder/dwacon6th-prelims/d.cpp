#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
#define rep1(i,n) for(int i=1;i<=int(n);++i)

#define debug(x) cerr<<(#x)<<": "<<(x)<<endl
template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }


int main(void){
    int n;
    cin >> n;
    map<int, int> a;
    rep1(i,n) cin >> a[i];
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    int T = 5;
    vector<int> res;
    rep1(k,n){
        priority_queue<int, vector<int>, greater<int>> waitQ;
        rep1(i,n) if (i != k) waitQ.push(i);
        res = {k};
        while ((int)waitQ.size() > T) {
            int t1 = waitQ.top(); waitQ.pop();
            int t2 = waitQ.top(); waitQ.pop();
            if (a[res.back()] != t1) {
                res.push_back(t1);
                waitQ.push(t2);
            } else {
                res.push_back(t2);
                waitQ.push(t1);
            }
        }
        T = waitQ.size();
        vector<int> v;
        while(waitQ.size()) {
            v.push_back(waitQ.top());
            waitQ.pop();
        }
        bool ok;
        do {
            ok = true;
            rep(i,T) res.push_back(v[i]);
            rep(i,T) {
                if (a[res[n-1-T+i]] == res[n-T+i]) {
                    ok = false;
                }
            }
            if (ok) break;
            rep(i,T) res.pop_back();
        } while(next_permutation(all(v)));
        if (ok) break;
    }

    rep(i,n){
        cout << (res[i]) << (i < n-1 ? " " : "\n");
    }
    return 0;
}

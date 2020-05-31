#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
const int INF = 1e9;

using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<P> p(n);
    multiset<int> bl, br;
    rep(i,n) {
        int l, r;
        cin >> l >> r;
        r++;
        p[i] = {l,r};
        bl.insert(l);
        br.insert(r);
    }
    sort(all(p));

    int res = 0;
    int al = 0, ar = INF;
    rep(i,n-1){
        int l = p[i].first;
        int r = p[i].second;
        al = max(al, l);
        ar = min(ar, r);
        bl.erase(bl.find(l));
        br.erase(br.find(r));

        int pointL = max(0, ar-al);
        int pointR = max(0, (*br.begin())-(*bl.rbegin()));
        res = max(res, pointL + pointR);
    }

    multiset<int> sl,sr;
    rep(i,n){
        sl.insert(p[i].first);
        sr.insert(p[i].second);
    }
    rep(i,n){
        int l = p[i].first;
        int r = p[i].second;
        sl.erase(sl.find(l));
        sr.erase(sr.find(r));
        res = max(res, (r-l) + max(0, (*sr.begin())-(*sl.rbegin())));
        sl.insert(l);
        sr.insert(r);
    }
    cout << res << endl;
    return 0;
}

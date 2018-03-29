#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;


int main () {
    int n = 10;
    vector<int> v(n);
    rep(i,n) v[i] = i*10;
    ostream_iterator<int> out_it (cout,", ");
    copy(all(v), out_it);
    cout<<endl;
    
    set<int> st;
    rep(i,n) st.insert(i*i);
    copy(all(st), out_it);
    cout<<endl;

    return 0;
}


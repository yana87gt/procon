#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

const int inf = 99999999;
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
vector<int> lis_fast(const vector<int>& a) {
  const int n = a.size();
  vector<int> A(n, inf);
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[i] = index_of(A, a[i]);
    A[ id[i] ] = a[i];
  }
  int m = *max_element(id.begin(), id.end());
  vector<int> b(m+1);
  for (int i = n-1; i >= 0; --i)
    if (id[i] == m) b[m--] = a[i];
  return b;
}

int main(void){
    int N;
    cin>>N;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    cout<<lis_fast(a).size()<<endl;
    return 0;
}

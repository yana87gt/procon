#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
const int INF = 1e9;

int N,A,B,C;
vector<int> x;

int calc(int a, int b, int c) {
    return 
        abs(accumulate(x.begin(), x.begin() + a, 0) - A) + (a-1)*10 +
        abs(accumulate(x.begin()+a, x.begin() + b, 0) - B) + (b-a-1)*10 +
        abs(accumulate(x.begin()+b, x.begin() + c, 0) - C) + (c-b-1)*10;
}

int main(void){
    cin >> N >> A >> B >> C;
    x.resize(N);
    rep(i,N) cin >> x[i];
    sort(all(x));
    int res = INF;
    do {
        rep(c,N+1) rep(b,c) rep(a,b){
            if (a == 0) continue;
            res = min(res, calc(a,b,c));
        }
    } while(next_permutation(all(x)));
    cout << res << endl;
    return 0;
}

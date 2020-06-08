#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int N, Q;
    cin >> N >> Q;
    map<int, int> up, down;
    rep1(i,N){
        down[-i] = i;
        down[i] = -i;
        up[-i] = i;
        up[i] = -i;
    }
    rep(q,Q){
        int f,t,x;
        cin >> f >> t >> x;
        int w = down[-f];
        int y = down[x];
        int z = down[-t];

        up[z] = x;
        down[x] = z;

        up[w] = -t;
        down[-t] = w;

        down[-f] = y;
        up[y] = -f;
    }
    map<int, int> res;
    rep1(i,N){
        for (int c = up[-i]; c != -i; c = up[c]) {
            res[c] = i;
        }
    }
    rep1(i,N) {
        cout << res[i] << endl;
    }

    return 0;
}

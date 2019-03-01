#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define bit(k) (1<<(k))

int n, K;
vector<int> group[18];
int a[18];

void make_group(int i, vector<int> &sub){
    if (sub.size() > 3) return;
    if (i == n) {
        int sum = 0;
        int num = sub.size();
        if (num == 0) return;
        rep(j,num) {
            sum += a[sub[j]];
        }
        if (sum <= K*num || num == 1) {
            int bit = 0;
            rep(j,num) {
                bit |= bit(sub[j]);
            }
            group[sub[0]].push_back(bit);
        }
        return;
    }
    sub.push_back(i);
    make_group(i+1, sub);
    sub.pop_back();
    make_group(i+1, sub);
}


int main(void){
    cin >> n >> K;
    rep(i,n) cin >> a[i];

    vector<int> sub;
    make_group(0, sub);

    map<int, ll> cur;
    cur[0] = 1;
    rep(i,n) {
        map<int, ll> nxt;
        int bit = 1<<i;
        for (auto itr : cur) {
            int cur_mask = itr.first;
            if (cur_mask & bit) {
                nxt[cur_mask] += cur[cur_mask];
            } else {
                for (int g_mask : group[i]) {
                    if ((g_mask & cur_mask) == 0) {
                        nxt[g_mask | cur_mask] += cur[cur_mask];
                    }
                }
            }
        }
        cur = nxt;
    }
    cout << cur[(1<<n)-1] << endl;
    return 0;
}

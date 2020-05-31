#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

struct T { ll value; int id; bool isB; };

int main(void){
    int n;
    cin >> n;
    vector<T> t;

    rep(i,n){
        ll a,b;
        cin >> a >> b;
        t.push_back({a,i,false});
        t.push_back({b,i,true});
    }

    sort(all(t), [](T x, T y){
        return x.value != y.value ? x.value < y.value : x.id < y.id;
    });
    vector<vector<bool>> low(n, {0,0});
    rep(i,n){
        low[t[i].id][t[i].isB] = true;
    }

    int HH = 0, LL = 0, HL = 0, LH = 0;
    ll sum = 0;
    rep(i,n){
        if ( low[i][0] &&  low[i][1]) LL++;
        if (!low[i][0] && !low[i][1]) HH++;
        if (!low[i][0] &&  low[i][1]) HL++;
        if ( low[i][0] && !low[i][1]) LH++;
        sum += t[i].value;
    }

    if (LL > 0 || LH == n || HL == n) {
        cout << sum << endl;
    } else if (t[n].id != t[n-1].id) {
        cout << sum - t[n-1].value + t[n].value << endl;
    } else if (sum - t[n-2].value + t[n].value < sum - t[n-1].value + t[n+1].value) {
        cout << sum - t[n-2].value + t[n].value << endl;
    } else {
        cout << sum - t[n-1].value + t[n+1].value << endl;
    }
    
    return 0;
}

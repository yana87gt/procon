#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()

int order(vector<int> v){
    int n = v.size();
    vector<int> a(n);
    rep(i,n) a[i] = i+1;
    int res = 0;
    do{
        res++;
        bool same = true;
        rep(i,n){
            if (a[i] != v[i]) same = false;
        }
        if (same) break;
    }while(next_permutation(all(a)));
    return res;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    cout << abs(order(a) - order(b)) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int n,d;
    cin >> n >> d;
    vector<vector<int>> p(n);
    rep(i,n){
        rep(j,d){
            int x;
            cin >> x;
            p[i].push_back(x);
        }
    }
    int cnt = 0;
    rep(i,n)rep(j,i){
        int sum = 0;
        rep(k,d){
            sum += (p[i][k]-p[j][k])*(p[i][k]-p[j][k]);
        }
        int root = sqrt(sum);
        if (root*root == sum) cnt ++;
    }
    cout << cnt << endl;
    return 0;
}

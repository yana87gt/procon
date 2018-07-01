#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()

using P = pair<int,int>;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n),d(n);
    vector<bool> moved(n);
    vector<P> order;
    rep(i,n){
        cin>>a[i]>>d[i];
        order.push_back({a[i], -i});
    }
    sort(all(order));
    int sum = 0;
    for(int from = 0; from < n;){
        int i = - order[from].second;
        if(!moved[i] && d[i] > 0){
            moved[i] = true;
            P p = {a[i]+d[i], -i};
            int to = lb(order, p);
            sum += to - from - 1;
            order.insert(order.begin()+to, p);
            order.erase(order.begin()+from);
        }else{
            from++;
        }
    }
    for(int from = n-1; from >= 0;){
        int i = - order[from].second;
        if(!moved[i] && d[i] < 0){
            moved[i] = true;
            P p = {a[i]+d[i], -i};
            int to = lb(order, p);
            sum += from - to;
            order.erase(order.begin()+from);
            order.insert(order.begin()+to, p);
        }else{
            from--;
        }
    }
    cout<<sum<<endl;
    return 0;
}

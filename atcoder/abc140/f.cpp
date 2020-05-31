#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)


int main(void){
    int n;
    cin >> n;
    int m = 1<<n;
    multiset<int> s;
    rep(i,m){
        int x;
        cin >> x;
        s.insert(-x);
    }
    vector<int> pars = {*s.begin()};

    s.erase(s.begin());
    while(s.size()){
        int k = pars.size();
        rep(i,k){
            auto itr = s.upper_bound(pars[k-1-i]);
            if (itr == s.end()) {
                cout << "No" << endl;
                return 0;
            }
            pars.push_back(*itr);
            s.erase(itr);
        }
    }
    cout << "Yes" << endl;

    return 0;
}

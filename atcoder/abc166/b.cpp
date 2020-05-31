#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

int main(void){
    int n, k;
    cin >> n >> k;
    set<int> st;
    rep1(i,n) st.insert(i);
    rep(i,k){
        int d;
        cin >> d;
        rep(j,d){
            int a;
            cin >> a;
            st.erase(a);
        }
    }
    cout << st.size() << endl;
    return 0;
}

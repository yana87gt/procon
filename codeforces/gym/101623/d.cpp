#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(int)(n);(i)++)
typedef long long ll;

int main() {
    int n,m;
    cin>>n;
    vector<string> s(n);
    map<string,string> st;
    rep(i,n){
        cin>>s[i];
        st[s[i]] = "";
    }
    cin>>m;
    map<string,int> ok,ng;
    rep(i,m){
        string d,e,c;
        cin>>d>>e>>c;
        if(st.find(d) == st.end()) continue;
        st[d] = e;
        if(c=="correct") ok[d]++;
        else ng[d]++;
    }
    
    ll sum = 1, ok_sum = 1;
    rep(i,n){
        sum *= (ok[s[i]]+ng[s[i]]);
        ok_sum *= (ok[s[i]]);
    }
    ll ng_sum = sum - ok_sum;
    if(sum>1){
        cout<<ok_sum<<" correct"<<endl;
        cout<<ng_sum<<" incorrect"<<endl;
    }else{
        rep(i,n) cout<<st[s[i]]<<(i<n-1 ? " " : "\n");
        cout<<((ok_sum == 1) ? "correct" : "incorrect")<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)


vector<int> func(vector<int> &v){
    vector<int> v2;
    for(int x : v){
        v2.push_back(x*2);
    }
    cout<<(&v2)<<endl;
    // return forward<vector<int>>(v2);
    return move(v2);
    // return v2;
}
class test
{
public:
    bool flag;
    test(){}
    ~test(){}
};

int main () {
    vector<test*> v;
    rep(i,30){
        test* t = new test;
        v.push_back(t);
        cout<<t->flag<<endl;
    }
    // vector<int> v = {3,1,4};
    // vector<int> &&v2 = func(v);
    // cout<<(&v2)<<endl;
    // for(int x : v2){
    //     cout<<x<<endl;
    // }
    // string x = "hoge";
    // cout<<&x<<endl;
    // string y = move(x);
    // cout<<&x<<endl;
    // cout<<&y<<endl;

/*
    int n = 10;
    vector<int> v(n);
    rep(i,n) v[i] = i*10;
    ostream_iterator<int> out_it (cout,", ");
    copy(all(v), out_it);
    cout<<endl;
    
    set<int> st;
    rep(i,n) st.insert(i*i);
    copy(all(st), out_it);
    cout<<endl;
*/

    return 0;
}

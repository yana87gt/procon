#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

void print_vec(vector<int> v){
    printf("%s\n",__func__ );
    for(auto x:v) cout<<x<<endl;
}

int main(void){
    vector<int> v;
    v = {1,1,4,5,1,4};
    print_vec(v);
    v = {};
    print_vec(v);
    print_vec({3,3,4});

    vector<vector<int>> vvi;
    vvi = {{1,2},{3,4},{5,6}};
    for(auto vi : vvi)print_vec(vi);

    return 0;
}

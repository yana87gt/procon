#include <bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define ub(s,x) upper_bound(all(s),x)-s.begin()

vector<int> v;

void make_753(int i, string s, bool in7, bool in5, bool in3){
    if(i==0){
        if(in7 && in5 && in3) v.push_back(stoi(s));
        return;
    }
    make_753(i-1, s+"7", true, in5, in3);
    make_753(i-1, s+"5", in7, true, in3);
    make_753(i-1, s+"3", in7, in5, true);
}

int main(void){
    rep1(i,9){
        make_753(i,"",0,0,0);
    }
    sort(all(v));
    int n;
    cin>>n;
    cout << ub(v,n) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define bit(k) (1ULL<<(k))
#define debug(x) cerr<<#x<<": "<<x<<endl;
using ull = unsigned long long;

struct Float{
    ull bin;
    int m;
    Float(string str_bin){
        bin = bitset<52>(str_bin).to_ullong();
        bin |= bit(52);
        m = 0;
    }
    void print(){
        cout<<bitset<12>(m)<<bitset<53>(bin).to_string().substr(1,52)<<endl;
    }
};

Float twice(Float x){
    x.m++;
    return x;
}

Float add(Float x, Float y){
    if(x.m < y.m) swap(x,y);
    y.bin >>= x.m-y.m;
    x.bin += y.bin;
    if(x.bin & bit(53)){
        x.bin >>= 1;
        x.m++;
    }
    while(x.bin>0 && !(x.bin & bit(52))){
        x.bin <<= 1;
        x.m--;
    }
    return x;
}

Float mul(Float x, ull r){
    if(r == 1) return x;
    if(r & 1) return add(mul(twice(x), r/2), x);
    return mul(twice(x), r/2);
}

int main(){
    ull n;
    while(cin>>n, n){
        string s;
        cin>>s;
        mul(Float(s), n+1).print();
    }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

// m桁の短歌数の総数
ll total(int m){
    return 81*(bit(m-1)-1);
}

string rec(ll n,int m,int f){
    rep(x,10){
        ll block = (f != x ? bit(m-1) : (bit(m-1)-1)*9);
        if(n >= block){
            n -= block;
        }else{
            string str = to_string(x);
            if(f == x){
                str += rec(n,m-1,f);
            }else{
                if(f < x) swap(f,x);
                for(int k = m-2; k >= 0; k--){
                    str += to_string(n&bit(k) ? f : x);
                }
            }
            return str;
        }
    }
    assert(false);
}

int main(){
    ll n;
    while(cin>>n, n){
        n--;
        int m = 2;
        while(n >= total(m)){
            n -= total(m);
            m++;
        }
        ll block = total(m)/9;
        int f = 1 + n/block;
        n %= block;
        cout<<to_string(f)<<rec(n,m-1,f)<<endl;
    }
    return 0;
}

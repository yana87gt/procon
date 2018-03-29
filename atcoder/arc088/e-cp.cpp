#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl

template<typename Type>

class BIT {
    public: //1-index
    vector<Type> bit;
    int n;
    BIT(int size){
        n = size+1;
        bit = vector<Type>(n+1,0);
    }

    void add(int i,Type x){
        while(i<=n){
            bit[i] += x;
            i += i&-i;
        }
    }

    Type sum(int i){
        int ret=0;
        while(i>0){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }

    Type range(int l,int r){
        return sum(r)-sum(l-1);
    }
};


int main(void){
    string s;
    cin>>s;
    int n = s.size();
    s = "_" + s;
    deque<int> p[26];
    BIT<int> bit(n);
    rep1(i,n){
        p[s[i]-'a'].push_back(i);
        bit.add(i,1);
    }

    int odd = 0;
    rep(i,26) if(p[i].size()&1) odd++;
    if(odd>1) {
        cout<<-1<<endl;
        return 0;
    }
    long r = 0;
    int v = n;
    rep1(i,n)if(bit.sum(i)-bit.sum(i-1) == 1){
        auto &d = p[s[i]-'a'];
        if(d.size()==1){
            r += v/2;
            bit.add(i,-1);
            d.clear();
            v--;
        }else{
            int x = d.front(); d.pop_front();
            int y = d.back(); d.pop_back();
            r += v - bit.sum(y);
            bit.add(x,-1);
            bit.add(y,-1);
            v -= 2;
        }
    }
    cout<<r<<endl;
    return 0;
}

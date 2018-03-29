#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

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
};


int solve(){
    string s;
    cin>>s;
    int n = s.size();
    if(n==1) return 0;
    s = "_"+s;
    int cnt[26] = {};
    vector<int> p(n+1),pp(n+1);
    rep1(i,n){
        char c = s[i]-'a';
        cnt[c]++;
        p[i] = cnt[c];
    }

    int odd=0;
    rep(i,26){
        if(cnt['a'+i]%2 == 1) odd++;
    }
    if(odd>1) return -1;

    
    int l=1,m=n/2+1,r=(n+3)/2;
    rep1(i,n){
        char c = s[i]-'a';
        if((cnt[c]&1) && p[i] == cnt[c]/2+1){
            pp[i] = m;
        }else if(p[i] <= cnt[c]/2){
            pp[i] = l;
            l++;
        }else{
            pp[i] = r;
            r++;
        }
    }
    //s->x

    vector<int> x(n+1);
    rep1(i,n){
        x[pp[i]] = s[i]-'a';
    }
    vector<int> a,c;
    rep1(i,m-1){
        a.push_back(x[i]);
        c.push_back(x[n+1-i]);
    }

    



}

int main(void){
    cout<<solve(s)<<endl;
    return 0;
}

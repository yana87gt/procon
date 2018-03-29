#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

void solve(int a,int b,int c,int d){
    int seqa = ceil(1.0*max(a,b)/(min(a,b)+1));
    bool tail = max(a,b)<=(min(a,b)*2);
    vector<int> va,vb;
    if(a>b){
        while(a>0){
            if(a>=seq)va.push_back(seq);
            else va.push_back(a);
            a-=seq;
        }
        int as = va.size();
        int bs = as-1+tail;
        // bs = 何この区間があるか
        // bの個数
        // ex 10, 3 ->4
        // ex 10,7 -> 2
        // ex 10,5 -> 2
        int seqb = ceil(1.0*b/bs);


    }
}

/*
A=10, B=3
aaabaaabaabaa

A=10, B=1 (10/(1+1) = 5)
aaaaabaaaaa

A=10, B=2 (10/(2+1) = 3. = 4)
aaaabaaaabaa

A=10, B=3 (10/(3+1) = 2.5 = 3)
aaabaaabaaaba

A=10, B=4 (10/(4+1) = 2)
aabaabaabaabaa
A=10, B=5 (10/(5+1) = 1._)
aabaabaabaabaab
A=10, B=6
aabaabaabaabaabb
A=10, B=7
aabaabaabaabbaabb
A=10, B=8
aabaabaabbaabbaabb
A=10, B=9
aabaabbaabbaabbaabb
A=10, B=10
aabbaabbaabbaabbaabb

A=10, B=5
aabaabaabaabaab
A=11, B=5
aabaabaabaabaaba
A=12, B=5
aabaabaabaabaabaa
A=13, B=5
aaabaabaabaabaabaa
A=6,  B=4
aabaabaabb
*/

int main(void){
    int q;
    cin>>q;
    rep(_,q){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }
    return 0;
}

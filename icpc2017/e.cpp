#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

string s;
int x;
int a,b,c,d;

bool ev(){
    if(s[x]=='('){
        x++;
        bool e = ev();
        if(s[x]=='^'){
            x++;
            e |= ev();
        }
        else if(s[x]=='*'){
            x++;
            e &= ev();
        }
        else {
            assert(false);
        }
        assert(s[x] == ')');
        x++;
        return e;
    }
    if(s[x]=='-'){
        x++;
        return ev();
    }
    if(s[x]=='0'){ x++; return 0; }
    if(s[x]=='1'){ x++; return 0; }
    if(s[x]=='a'){ x++; return a; }
    if(s[x]=='b'){ x++; return b; }
    if(s[x]=='c'){ x++; return c; }
    if(s[x]=='d'){ x++; return d; }
    assert(false);
}

bool eval(){
    x = 0;
    return ev();
}




int main(){
    s = "-(a*(b^c)";
    while(cin >> s, s!="."){
        bool res[2][2][2][2];
        for(a=0; a<2; a++){
            for(b=0; b<2; b++){
                for(c=0; c<2; c++){
                    for(d=0; d<2; d++){
                        dbg(eval());
                        res[a][b][c][d] = eval();
                    }
                }
            }
        }

    }

    return 0;
}
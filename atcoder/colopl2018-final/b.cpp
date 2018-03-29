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
string res;
int idx=0;
void solve(char op){
    while(true){
        if(idx == (int)s.size())return;
        char c = s[idx];
        if(isdigit(c)){
            res += c;
            idx++;
        }else if(c == ')'){
            res += c;
            idx++;
            return;
        }else if(c == ','){
            res += op;
            idx++;
        }else{
            res += '(';
            idx+=2;
            solve(c);
        }
    }

}

int main(void){
    cin>>s;
    solve('_');
    cout<<res<<endl;
    return 0;
}

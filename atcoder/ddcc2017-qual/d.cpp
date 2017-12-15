#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int H,W,A,B;
    cin>>H>>W>>A>>B;
    vector<string> s(H);
    rep(y,H) cin>>s[y];
    map<int,int> cnt;
    int symA = 0, symB = 0;
    bool SymStart = true;
    rep(y,H/2)rep(x,W/2){
        int yy=H-y-1,xx=W-x-1;
        int c4[] = {s[y][x],s[yy][x],s[y][xx],s[yy][xx]};
        int dir4=0;
        rep(i,4)if(c4[i]=='S')dir4++;
        cnt[dir4]++;
        if(dir4 == 2){
            if(s[y][x] == s[yy][xx]) SymStart = false;
            if(s[y][x] == s[yy][x]) symA++;
            if(s[y][x] == s[y][xx]) symB++;
        }
    }
    if(cnt[1] || cnt[3] || (symA && symB)) SymStart = false;

    long long sum = A+B;
    sum += max((symA+cnt[3])*A,(symB+cnt[3])*B);
    sum += (A+B+max(A,B))*cnt[4];
    if(SymStart){
        if(symA) sum -= A;
        else if(symB) sum -= B;
        else sum -= A+B;
    }
    cout<<sum<<endl;
    return 0;
}

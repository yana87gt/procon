#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Team{
    ll size,hp;
    bool pr;
    ll rem(){
        if(pr) return (hp+1)/2;
        return (size <= hp) ? size : hp;
    }
};


int solve(ll n, ll m, int pr){
    Team t[2] = {{n,n*2LL,false},{m,m*2LL,false}};
    t[pr].pr = true;
    int turn = 0, cnt = 0;
    while(true){
        ll attack = t[turn].rem();
        t[(turn+1)%2].hp -= attack;
        if(t[0].rem()>0 && t[1].rem()>0){
            cnt++;
            turn = (turn+1)%2;
        }else{
            break;
        }
    }
    return cnt;
}

int main(void){
    ll n,m;
    cin>>n>>m;
    cout<<min(solve(n,m,0), solve(n,m,1))<<endl;
    return 0;
}

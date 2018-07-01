#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define updmax(dp,x) dp=(dp.first == 0 ? x : max(dp,x))

using P = pair<int,int>;

int main(void){
    int n;
    while(cin>>n, n){
        vector<int> p(n);
        rep(i,n) cin>>p[i];
        map<int,P> cur; // cur[coin] = <get,pay>
        cur[0] = P(0,0);
        rep(i,n){
            map<int,P> nxt;
            for(auto &itr : cur){
                int coin = itr.first;
                int k = itr.second.first;
                int pay = itr.second.second;
                updmax(nxt[coin], P(k,pay));
                pay -= p[i];
                coin += (1000-p[i]%1000)%1000;
                if(coin >= 500){
                    updmax(nxt[coin-500], P(k+1, pay));
                }else if(p[i]%1000){
                    updmax(nxt[coin], P(k,pay));
                }
            }
            cur = move(nxt);
        }

        P res = {0,0};
        for(auto itr : cur){
            res = max(res,itr.second);
        }
        cout<<res.first<<" "<<-res.second<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int n;
        cin>>n;
        using P = pair<int,char>;
        priority_queue<P> qu;
        rep(i,n){
            P p;
            cin>>p.first;
            p.second = 'A'+i;
            qu.push(p);
        }
        printf("Case #%d:",_+1);
        while(!qu.empty()){
            P p1 = qu.top(); qu.pop();
            P p2 = qu.top(); qu.pop();
            if(p1.first==1 && qu.size()==1){
                printf(" %c", p1.second);
                qu.push(p2);
            }else{
                printf(" %c%c", p1.second, p2.second);
                p1.first--; p2.first--;
                if(p1.first>0) qu.push(p1);
                if(p2.first>0) qu.push(p2);
            }
        }
        printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;

ll seg(string s){
    ll m = s.size();
    ll sum = 0, cnt = 0;
    rep(i,m){
        if(s[i]=='A'){
            cnt++;
            sum += cnt;
        }else{
            cnt = 0;
        }
    }
    return sum;
}

int main(void){
    ll n;
    string s;
    cin>>n>>s;
    ll m = s.size();
    int b1=m,b2=m;
    rep(i,m){
        if(s[i] == 'B'){
            b1=i;
            break;
        }
    }
    rep(i,m){
        if(s[m-1-i] == 'B'){
            b2=m-1-i;
            break;
        }
    }
    if(b1==m){
        cout<<(1+n*m)*n*m/2<<endl;
    }else{
        ll score1 = seg(s.substr(0,b1));
        ll score2 = seg(s.substr(b1,b2-b1))*n;
        ll score3 = seg(s.substr(b2,m-b2)+s.substr(0,b1))*(n-1);
        ll score4 = seg(s.substr(b2,m-b2));
        cout<<score1+score2+score3+score4<<endl;
    }
    return 0;
}

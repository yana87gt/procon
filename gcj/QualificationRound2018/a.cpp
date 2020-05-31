#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

int sum(string p){
    int res = 0, power = 1;
    for(char c : p){
        if(c=='C'){
            power <<= 1;
        }else{
            res += power;
        }
    }
    return res;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int d;
        string p;
        cin>>d>>p;
        printf("Case #%d: ",_+1);
        if(count(all(p), 'S') > d){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        int n = p.size();
        int cnt = 0;
        while(sum(p) > d){
            for(int i = n-2; i>=0; i--){
                if(p.substr(i,2) == "CS"){
                    swap(p[i],p[i+1]);
                    break;
                }
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

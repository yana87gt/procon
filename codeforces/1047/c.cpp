#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

#define SIZE 15000010
vector<int> divisor(SIZE,1);
void init(){
    for(int i = 2; i < SIZE; i++){
        if(divisor[i] != 1)continue;
        for(int j=i;j<SIZE;j+=i){
            divisor[j] = i;
        }
    }
}

int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    int g = a[n-1];
    rep(i,n-1){
        g = gcd(g,a[i]);
    }
    bool ng = true;
    rep(i,n){
        a[i] /= g;
        if(a[i] > 1) ng = false;
    }

    if(ng){
        cout<<-1<<endl;
        return 0;
    }
    map<int,int> mp;
    rep(i,n){
        int x = a[i];
        while(x!=1){
            int p = divisor[x];
            if(x%p==0){
                mp[p]++;
                while(x%p==0) x/=p;
            }
        }
    }

    int res = 1;
    for(auto itr : mp){
        res = max(res, itr.second);
    }
    cout<<n-res<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define INF 1e9

int n;

int LIS(vector<int> v){
    vector<int> dp(n, INF);
    rep(i,n){
        *lower_bound(all(dp),v[i]) = v[i];
    }
    return lower_bound(all(dp),INF) - dp.begin();
}

vector<int> make(int a, int b){
    vector<int> v;
    b--;
    int mx = n, mn = 1, rem = n;
    bool modeA = true;
    while(rem){
        vector<int> seq;
        if(modeA){
            rep(i,a){
                seq.push_back(mx);
                mx--;
                rem--;
                if(rem==0)break;
            }
            a--;
            modeA = false;
        }else{
            rep(i,b){
                seq.push_back(mn);
                mn++;
                rem--;
                if(rem==0)break;
            }
            b--;
            modeA = true;
        }
        reverse(all(seq));
        v.insert(v.end(),all(seq));
    }
    return v;
}

int main(void){
    int a,b;
    cin>>n>>a>>b;
    vector<int> v = make(a,b);
    vector<int> rev = v;
    reverse(all(rev));
    if(LIS(v) == a && LIS(rev) == b){
        rep(i,n){
            printf("%d%c",v[i],(i<n-1 ? ' ' : '\n'));
        }
    }else{
        cout<<-1<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()

bool solve(int Y,vector<string> s,bool rec){
    rep(y,Y){
        sort(all(s[y]));
    }
    sort(all(s));
    map<string,int> mp;
    rep(y,Y){
        mp[s[y]]++;
    }
    int odd = 0;
    string odd_str="";
    for(auto itr:mp){
        if(itr.second % 2 == 0)continue;
        else {
            odd_str = itr.first;
            odd++;
        }
    }
    if(odd > 1) return false;
    else if(odd == 1 && !rec){
        int m = odd_str.size();
        vector<string> ss(m);
        rep(i,m){
            ss[i].push_back(odd_str[i]);
        }
        return solve(m,ss,true);
    }
    else return true;
}

int main(void){
    int Y,X;
    cin>>Y>>X;
    vector<string> s(Y),t(X);
    rep(y,Y){
        cin>>s[y];
        rep(x,X){
            t[x].push_back(s[y][x]);
        }
    }
    cout<<((solve(Y,s,false) && solve(X,t,false)) ? "YES" : "NO")<<endl;
    return 0;
}

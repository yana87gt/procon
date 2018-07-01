#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(s) s.begin(),s.end()
#define uniq(a) a.erase(unique(all(a)),a.end())

int main(void){
    int n;
    while(cin>>n, n){
        vector<string> s(n);
        int a[256] = {};
        bool not_zero[256] = {};
        string c;
        rep(i,n){
            cin>>s[i];
            int k = s[i].size();
            if(k>1) not_zero[s[i][0]] = true;
            reverse(all(s[i]));
            rep(j,k){
                a[s[i][j]] += pow(10,j)*(i==n-1 ? -1 : 1);
                c += s[i][j];
            }
        }

        sort(all(c));
        uniq(c);
        c += string(10-(int)c.size(), '-');
        sort(all(c));
        int res = 0;
        do{
            if(not_zero[c[0]]) continue;
            int sum = 0;
            rep(i,10) sum += i*a[c[i]];
            if(sum == 0) res++;
        }while(next_permutation(all(c)));
        cout<<res<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n;
string s[12];

int dfs(int now, int carry, const vector<int> &use)
{
    if(now==0)
    {
        if(carry==0) return 1;
    }
    
    int ret=0;

    vector<char> vv;
    rep(i,n)
    {
        if('a'<=s[i][now] && s[i][now]<='j')
        {
            bool found=false;
            rep(j,10) if(use[j]==s[i][now]-'a') found=true;
            if(!found) vv.pb(s[i][now]);
        }
    }
    sort(all(vv));
    vv.erase(unique(all(vv)),vv.end());

    int VV=vv.size();

    printf("now=%d\n", now);
    rep(i,VV) printf(" %c", vv[i]);
    printf("\n");

    vector<int> perm(10);
    rep(i,10) perm[i]=i;

    do
    {
        rep(i,VV) printf(" %d", perm[i]);
        printf("\n");

        bool valid=true;
        vector<int> nxuse(use);

        //文字vv[i]をperm[i]に割り当て
        rep(i,vv.size())
        {
            if(nxuse[perm[i]]!=-1) nxuse[perm[i]]=vv[i]-'a';
            else
            {
                valid=false;
                break;
            }
        }

        if(valid)
        {
            int sum=carry;
            rep(i,n-1) sum+=use[s[i][now]-'a'];

            char focus=s[n-1][now];
            int idx=-1;
            rep(i,10)
            {
                if(use[i]==focus-'a')
                {
                    idx=i;
                    break;
                }
            }


            if(idx==-1)
            {
                int r=sum%10;
                if(nxuse[r]==-1)
                {
                    ret+=dfs(now-1,sum/10,nxuse);
                }
            }
            else
            {
                if(sum%10==idx)
                {
                    ret+=dfs(now-1,sum/10,nxuse);
                }
            }
        }

        reverse(perm.begin()+VV,perm.end());
    }
    while(next_permutation(all(perm)));


    return ret;
}

int main()
{
    while(cin >>n,n)
    {
        rep(i,n) cin >>s[i];

        vector<char> var;
        rep(i,n)rep(j,s[i].size()) var.pb(s[i][j]);

        sort(all(var));
        var.erase(unique(all(var)),var.end());

        //変換
        map<char,char> m;
        rep(i,var.size()) m[var[i]]='a'+i;
        rep(i,n)rep(j,s[i].size()) s[i][j]=m[s[i][j]];

        //桁を揃える
        rep(i,n)
        {
            while(s[i].size()<9) s[i]="0"+s[i];
        }

        rep(i,n) cout << s[i] << endl;
        vector<int> u(10,-1);

        cout << dfs(8,0,u) << endl;
    }
    return 0;
}

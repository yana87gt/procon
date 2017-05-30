#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;++i)
struct man{int r,h;};
struct answer{int w,l,d;};

int main()
{
    int i,n;
    int ct[100001][3]={};
    cin >> n;
    vector<man> v(n);
    vector<int> a(n);
    rep(i,n)
    {
        cin >> v[i].r >> v[i].h;
        a[i] = v[i].r;
        ++ct[v[i].r][v[i].h-1];
    }

    sort(a.begin(),a.end());

    vector<answer> ans(n);
    rep(i,n)
    {
        int left = lower_bound(a.begin(),a.end(),v[i].r)-a.begin();
        int right = upper_bound(a.begin(),a.end(),v[i].r)-a.begin()-1;

        //レートの違いによる勝敗
        ans[i].w = left;
        ans[i].l = n-1-right;
        //レートが同じ時
        ans[i].w += ct[v[i].r][(v[i].h)%3];
        ans[i].l += ct[v[i].r][(v[i].h+1)%3];
        //引き分けは自分を除く
        ans[i].d = ct[v[i].r][v[i].h-1]-1;
    }

    rep(i,n) cout<<ans[i].w<<' '<<ans[i].l<<' '<<ans[i].d<<endl;
}

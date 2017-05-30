#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
struct man{
	int yosen,win;
	bool operator<(const man& right)const{
		return (win==right.win ? yosen<right.yosen : win>right.win);
	}
};

int main(void){
	int T,N;
	cin>>T;
	rep(_,T){
		cin>>N;
		vector<string> s(N);
		vector<int> win(N);
		rep(i,N)cin>>s[i];
		rep(i,N)rep(j,N)if(s[i][j]=='o')win[i]++;
		vector<man> res(N);
		rep(i,N)res[i]={i+1,win[i]};
		sort(res.begin(),res.end());
		rep(i,N)cout<<res[i].yosen<<(i==N-1 ? "" : " ");
		cout<<endl;
	}
	return 0;
}

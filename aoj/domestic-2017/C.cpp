#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()

int main(void){
	int N,M;
	while(cin>>N>>M,N|M){
		vector<pair<int,int>> a(N+1),b(N+1); //max,min
		rep(i,M){
			int s,k,c;
			cin>>s>>k;
			rep(j,k){
				cin>>c;
				if(k==1) b[c]={s+b[c].first,j};
				a[c]={s+a[c].first,j};
			}
		}
		sort(all(a));
		sort(all(b));
		if(a[N].second == b[1].second){
			cout<<max(a[N].first-b[2].first,a[N-1].first-b[1].first)+1<<endl;
		}else{
			cout<<a[N].first-b[1].first<<endl;
		}
	}
	return 0;
}

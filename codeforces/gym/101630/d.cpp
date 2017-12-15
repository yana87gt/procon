#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
#define mp(a,b) make_pair((a), (b))
#define pb(a) push_back((a))

#define fi first
#define se second

using namespace std;

bool solve(){
	vector<pair<int,int>> a(3);
	rep(i,3) cin>>a[i].first;
	rep(i,3) a[i].second = 2-i;
	
	sort(all(a));

	if(a[0].first * a[1].first < a[2].first) return false;
	
	vector<vector<int>> res;
	
	vector<vector<bool>> v(a[0].first, vector<bool>(a[1].first, false));
	
	rep(i,a[1].fi){
		res.push_back({i%a[0].fi, i, 0});
		v[i%a[0].fi][i] = true;
	}
	
	int cnt = a[2].fi - a[1].fi;
	rep(i, a[0].fi) rep(j, a[1].fi) if(!v[i][j] && cnt>0){
		res.push_back({i, j, 0});
		cnt--;
	}
	
	cout << res.size() << endl;
	for(auto &p : res){
		printf("%d %d %d\n", p[a[1].se], p[a[0].se], p[a[2].se]);
	}

	return true;
}

int main(){
	if(!solve()) cout << "-1" << endl;
		
	return 0;
} 

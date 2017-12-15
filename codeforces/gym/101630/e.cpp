#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(s) s.begin(),s.end()
using namespace std;

vector<int> solve(){
	int n;
	cin >>n;
	vector<int> a(n);
	rep(i,n) cin >>a[i];

	vector<int> ret;

	vector<bool> ok(n,true);
	rep(i,n)if(a[i]<0) ok[i]=false;
	
	vector<int> ct(1001);
	rep(i,n)
	{
		//printf(" i = %d\n",i);
		if(a[i]>0) ++ct[a[i]];
		else if(a[i]<0){
			if(ct[-a[i]]<=0) return vector<int>({-191919});
			--ct[-a[i]];
		}
		else{
			bool f = false;
			vector<int> tmp(ct);
			for(int j=i+1; j<n; ++j){
				if(a[j]>0) ++tmp[a[j]];
				else if(a[j]<0){
					if(tmp[-a[j]]<=0){
						ret.push_back(-a[j]);
						++ct[-a[j]];
						f = true;
						break;
					}
					else --tmp[-a[j]];
				}
			}
			if(!f){
				ret.push_back(1);
				++ct[1];
			}
		}
	}

	return ret;
}

int main(){
	vector<int> ans = solve();
	if(ans.size()==0) cout << "Yes" << endl;
	else if(ans[0]==-191919) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		int A = ans.size();
		rep(i,A) printf("%d%c", ans[i], " \n"[i==A-1]);
	} 
	return 0;
} 
